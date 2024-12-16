#pragma once

#ifndef ARCHIVE_AST_EXPR_IMPL_BOOL_HPP
#define ARCHIVE_AST_EXPR_IMPL_BOOL_HPP

#include "archive/ast/expr/expr.hpp"
#include "archive/frontend/token.hpp"

namespace archive::ast
{
    class BoolExpr final : public Expr::Node<BoolExpr>
    {
    public:
        using Token = archive::frontend::Token;

    public:
        explicit BoolExpr(Token token);
        [[nodiscard]] auto token() const -> const Token&;
        [[nodiscard]] auto value() const -> bool;

    private:
        bool  m_value;
        Token m_literal;
    };
} // namespace archive::ast

#endif // ARCHIVE_AST_EXPR_IMPL_BOOL_HPP
