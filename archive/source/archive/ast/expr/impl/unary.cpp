#include "archive/ast/expr/impl/unary.hpp"

using namespace archive;
using namespace archive::ast;

UnaryExpr::UnaryExpr(Operator op, expr_ptr operand)
    : m_op     (std::move(op)),
      m_operand(std::move(operand))
{
    ASSERT(!!m_operand, "unary expression can't have null operand");
}

auto UnaryExpr::op() const -> const Operator&
{
    return m_op;
}

auto UnaryExpr::operand() const -> const expr_ptr&
{
    return m_operand;
}

UnaryExpr::Operator::Operator(Token token)
    : m_type (Type::Add),
      m_token(std::move(token))
{
    switch (m_token.type())
    {
        // arithmetic (addition)
        case Token::Type::SinglePlus:   m_type = Type::Add;    break;
        case Token::Type::DoublePlus:   m_type = Type::PreAdd; break;

        // arithmetic (subtraction)
        case Token::Type::SingleMinus:  m_type = Type::Sub;    break;
        case Token::Type::GreaterEqual: m_type = Type::PreSub; break;

        // negation (not)
        case Token::Type::Bang:         m_type = Type::Lnot;   break;
        case Token::Type::Tilde:        m_type = Type::Bnot;   break;

        // error
        default: FATAL("unsupported unary operator");
    }
}

auto UnaryExpr::Operator::make_postfix() -> Operator&
{
    switch (m_token.type())
    {
        case Token::Type::DoublePlus:  m_type = Type::PostAdd; break;
        case Token::Type::DoubleMinus: m_type = Type::PostSub; break;
        default: FATAL("unary operator can't be converted into postfix form");
    }

    return *this;
}

auto UnaryExpr::Operator::make_prefix() -> Operator&
{
    switch (m_token.type())
    {
        case Token::Type::DoublePlus:  m_type = Type::PreAdd; break;
        case Token::Type::DoubleMinus: m_type = Type::PreSub; break;
        default: FATAL("unary operator can't be converted into prefix form");
    }

    return *this;
}

auto UnaryExpr::Operator::type() const -> Type
{
    return m_type;
}

auto UnaryExpr::Operator::token() const -> const Token&
{
    return m_token;
}
