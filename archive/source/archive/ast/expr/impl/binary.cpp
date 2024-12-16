#include "archive/ast/expr/impl/binary.hpp"

using namespace archive;
using namespace archive::ast;

BinaryExpr::BinaryExpr(Operator op, expr_ptr lhs, expr_ptr rhs)
    : m_op (std::move(op)),
      m_lhs(std::move(lhs)),
      m_rhs(std::move(rhs))
{
    ASSERT(!!m_lhs, "binary expression can't have null lhs operand");
    ASSERT(!!m_rhs, "binary expression can't have null rhs operand");
}

auto BinaryExpr::op() const -> const Operator&
{
    return m_op;
}

auto BinaryExpr::lhs() const -> const expr_ptr&
{
    return m_lhs;
}

auto BinaryExpr::rhs() const -> const expr_ptr&
{
    return m_rhs;
}

BinaryExpr::Operator::Operator(Token token)
    : m_type (Type::Add),
      m_token(std::move(token))
{
    switch (m_token.type())
    {
        // arithmetic
        case Token::Type::SinglePlus:      m_type = Type::Add; break;
        case Token::Type::Slash:           m_type = Type::Div; break;
        case Token::Type::DoublePercent:   m_type = Type::Mod; break;
        case Token::Type::Star:            m_type = Type::Mul; break;
        case Token::Type::SinglePercent:   m_type = Type::Rem; break;
        case Token::Type::SingleMinus:     m_type = Type::Sub; break;

        // relational
        case Token::Type::DoubleEqual:     m_type = Type::Ceq; break;
        case Token::Type::GreaterEqual:    m_type = Type::Cge; break;
        case Token::Type::SingleGreater:   m_type = Type::Cgt; break;
        case Token::Type::LessEqual:       m_type = Type::Cle; break;
        case Token::Type::SingleLess:      m_type = Type::Clt; break;
        case Token::Type::BangEqual:       m_type = Type::Cnq; break;

        // logical
        case Token::Type::DoubleAmpersand: m_type = Type::Land; break;
        case Token::Type::DoubleVBar:      m_type = Type::Lor;  break;

        // bitwise
        case Token::Type::SingleAmpersand: m_type = Type::Band; break;
        case Token::Type::SingleVBar:      m_type = Type::Bor;  break;
        case Token::Type::Caret:           m_type = Type::Bxor; break;
        case Token::Type::DoubleLess:      m_type = Type::Bls;  break;
        case Token::Type::DoubleGreater:   m_type = Type::Brs;  break;

        // error
        default: FATAL("unsupported binary operator");
    }
}

auto BinaryExpr::Operator::type() const -> Type
{
    return m_type;
}

auto BinaryExpr::Operator::token() const -> const Token&
{
    return m_token;
}
