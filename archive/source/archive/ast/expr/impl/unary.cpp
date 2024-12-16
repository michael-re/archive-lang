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
    : m_type (Type::Pls),
      m_token(std::move(token))
{
    FATAL("method not yet implemented");
}

auto UnaryExpr::Operator::type() const -> Type
{
    return m_type;
}

auto UnaryExpr::Operator::token() const -> const Token&
{
    return m_token;
}
