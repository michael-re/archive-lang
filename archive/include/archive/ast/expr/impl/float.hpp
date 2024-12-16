#pragma once

#ifndef ARCHIVE_AST_EXPR_IMPL_FLOAT_HPP
#define ARCHIVE_AST_EXPR_IMPL_FLOAT_HPP

#include "archive/ast/expr/expr.hpp"
#include "archive/frontend/token.hpp"

namespace archive::ast
{
    class FloatExpr final : public Expr::Node<FloatExpr>
    {
    public:
        using Token = archive::frontend::Token;

    public:
        explicit FloatExpr(Token token);
        [[nodiscard]] auto token() const -> const Token&;
        [[nodiscard]] auto value() const -> double;

    private:
        double m_value;
        Token  m_literal;
    };
} // namespace archive::ast

#endif // ARCHIVE_AST_EXPR_IMPL_FLOAT_HPP
