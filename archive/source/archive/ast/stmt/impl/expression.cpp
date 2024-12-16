#include "archive/ast/stmt/impl/expression.hpp"

using namespace archive;
using namespace archive::ast;

ExpressionStmt::ExpressionStmt(expr_ptr expression)
    : m_expression(std::move(expression))
{
    ASSERT(!!m_expression, "expression statement can't have null expression");
}

auto ExpressionStmt::expression() const -> const expr_ptr&
{
    return m_expression;
}
