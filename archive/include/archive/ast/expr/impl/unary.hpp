#pragma once

#ifndef ARCHIVE_AST_EXPR_IMPL_UNARY_HPP
#define ARCHIVE_AST_EXPR_IMPL_UNARY_HPP

#include "archive/ast/expr/expr.hpp"
#include "archive/frontend/token.hpp"

namespace archive::ast
{
    class UnaryExpr final : public Expr::Node<UnaryExpr>
    {
    public:
        class Operator
        {
        public:
            using Token = archive::frontend::Token;
            enum class Type;
            struct Prefix{};
            struct Postfix{};

        public:
            explicit Operator(Token token);

            auto make_postfix() -> Operator&;
            auto make_prefix () -> Operator&;

            [[nodiscard]] auto type()  const -> Type;
            [[nodiscard]] auto token() const -> const Token&;

        private:
            Type  m_type;
            Token m_token;
        };

    public:
        explicit UnaryExpr(Operator op, expr_ptr operand);
        [[nodiscard]] auto op()      const -> const Operator&;
        [[nodiscard]] auto operand() const -> const expr_ptr&;

    private:
        Operator m_op;
        expr_ptr m_operand;
    };

    enum class UnaryExpr::Operator::Type
    {
        // arithmetic (addition)
        Add,        // (+)  unary plus
        PostAdd,    // (++) postfix addition
        PreAdd,     // (++) prefix addition

        // arithmetic (subtraction)
        Sub,        // (-)  unary minus
        PostSub,    // (--) postfix subtract
        PreSub,     // (--) postfix subtract

        // negation (not)
        Lnot,       // (!) logical not
        Bnot,       // (~) bitwise not
    };
} // namespace archive::ast

#endif // ARCHIVE_AST_EXPR_IMPL_UNARY_HPP
