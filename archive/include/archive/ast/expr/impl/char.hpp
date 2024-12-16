#pragma once

#ifndef ARCHIVE_AST_EXPR_IMPL_CHAR_HPP
#define ARCHIVE_AST_EXPR_IMPL_CHAR_HPP

#include "archive/ast/expr/expr.hpp"
#include "archive/frontend/token.hpp"

namespace archive::ast
{
    class CharExpr final : public Expr::Node<CharExpr>
    {
    public:
        using Token = archive::frontend::Token;

    public:
        explicit CharExpr(Token token);
        [[nodiscard]] auto token() const -> const Token&;
        [[nodiscard]] auto value() const -> char;

    private:
        char  m_value;
        Token m_literal;
    };
} // namespace archive::ast

#endif // ARCHIVE_AST_EXPR_IMPL_CHAR_HPP
