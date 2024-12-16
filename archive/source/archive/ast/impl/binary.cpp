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
    FATAL("method not yet implemented");
}

auto BinaryExpr::Operator::type() const -> Type
{
    return m_type;
}

auto BinaryExpr::Operator::token() const -> const Token&
{
    return m_token;
}
