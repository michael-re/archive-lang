#pragma once

#ifndef ARCHIVE_AST_EXPR_IMPL_INTEGER_HPP
#define ARCHIVE_AST_EXPR_IMPL_INTEGER_HPP

#include "archive/ast/expr/expr.hpp"
#include "archive/frontend/token.hpp"

namespace archive::ast
{
    class IntegerExpr final : public Expr::Node<IntegerExpr>
    {
    public:
        using Token = archive::frontend::Token;

    public:
        explicit IntegerExpr(Token token);
        [[nodiscard]] auto token() const -> const Token&;
        [[nodiscard]] auto value() const -> const std::string&;

    private:
        Token m_literal;
    };
} // namespace archive::ast

#endif // ARCHIVE_AST_EXPR_IMPL_INTEGER_HPP
