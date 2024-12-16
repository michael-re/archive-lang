#pragma once

#ifndef ARCHIVE_AST_EXPR_IMPL_BINARY_HPP
#define ARCHIVE_AST_EXPR_IMPL_BINARY_HPP

#include "archive/ast/expr/expr.hpp"
#include "archive/frontend/token.hpp"

namespace archive::ast
{
    class BinaryExpr final : public Expr::Node<BinaryExpr>
    {
    public:
        class Operator
        {
        public:
            using Token = archive::frontend::Token;
            enum class Type;

        public:
            explicit Operator(Token token);
            [[nodiscard]] auto type()  const -> Type;
            [[nodiscard]] auto token() const -> const Token&;

        private:
            Type  m_type;
            Token m_token;
        };

    public:
        explicit BinaryExpr(Operator op, expr_ptr lhs, expr_ptr rhs);
        [[nodiscard]] auto op()  const -> const Operator&;
        [[nodiscard]] auto lhs() const -> const expr_ptr&;
        [[nodiscard]] auto rhs() const -> const expr_ptr&;

    private:
        Operator m_op;
        expr_ptr m_lhs;
        expr_ptr m_rhs;
    };

    enum class BinaryExpr::Operator::Type
    {
        // arithmetic
        Add,    // (+)  addition
        Div,    // (/)  division
        Mod,    // (%%) modulo
        Mul,    // (*)  multiplication
        Rem,    // (%)  remainder
        Sub,    // (-)  subtraction

        // relational
        Ceq,    // (==) compare equal
        Cge,    // (>=) compare greater equal
        Cgt,    // (>)  compare greater than
        Cle,    // (<=) compare less equal
        Clt,    // (<)  compare less than
        Cnq,    // (!=) compare not equal

        // logical
        Land,   // (&&) logical and
        Lor,    // (||) logical or  (&)

        // bitwise
        Band,   // (&)  bitwise and
        Bor,    // (|)  bitwise or  (inclusive or)
        Bxor,   // (^)  bitwise xor (exclusive or)
        Bls,    // (<<) bitwise left shift
        Brs,    // (>>) bitwise right shift
    };
} // namespace archive::ast

#endif // ARCHIVE_AST_EXPR_IMPL_BINARY_HPP
