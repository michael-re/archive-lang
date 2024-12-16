#pragma once

#ifndef ARCHIVE_AST_STMT_IMPL_EXPRESSION_HPP
#define ARCHIVE_AST_STMT_IMPL_EXPRESSION_HPP

#include "archive/ast/stmt/stmt.hpp"
#include "archive/ast/expr/expr.hpp"

namespace archive::ast
{
    class ExpressionStmt final : public Stmt::Node<ExpressionStmt>
    {
    public:
        explicit ExpressionStmt(expr_ptr expression);
        [[nodiscard]] auto expression() const -> const expr_ptr&;

    private:
        expr_ptr m_expression;
    };
} // namespace archive::ast

#endif // ARCHIVE_AST_STMT_IMPL_EXPRESSION_HPP
