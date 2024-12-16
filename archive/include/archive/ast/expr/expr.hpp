#pragma once

#ifndef ARCHIVE_AST_EXPR_EXPR_HPP
#define ARCHIVE_AST_EXPR_EXPR_HPP

#include "archive/ast/expr/forward.hpp"

namespace archive::ast
{
    class Expr
    {
    public:
        template<typename Derived>
        class Node;

        template<bool IsConst>
        class BaseVisitor;

        using Visitor      = BaseVisitor<false>;
        using ConstVisitor = BaseVisitor<true>;

    public:
        explicit Expr() = default;
        virtual ~Expr() = default;

        virtual auto accept(Visitor&)            -> void = 0;
        virtual auto accept(ConstVisitor&) const -> void = 0;
    };

    template<bool IsConst>
    class Expr::BaseVisitor
    {
    public:
        template<typename T>
        using conditional = std::conditional_t<IsConst, const T, T>;

    public:
        explicit BaseVisitor() = default;
        virtual ~BaseVisitor() = default;

        virtual auto visit(conditional<BinaryExpr>&)  -> void = 0;
        virtual auto visit(conditional<BoolExpr>&)    -> void = 0;
        virtual auto visit(conditional<CharExpr>&)    -> void = 0;
        virtual auto visit(conditional<FloatExpr>&)   -> void = 0;
        virtual auto visit(conditional<IntegerExpr>&) -> void = 0;
        virtual auto visit(conditional<UnaryExpr>&)   -> void = 0;
    };

    template<typename Derived>
    class Expr::Node : public Expr
    {
    public:
        virtual auto accept(Visitor& visitor) -> void override final
        {
            visitor.visit(*static_cast<Derived*>(this));
        }

        virtual auto accept(ConstVisitor& visitor) const -> void override final
        {
            visitor.visit(*static_cast<const Derived*>(this));
        }

        template<typename... Args>
        [[nodiscard]] static auto make(Args&&... args) -> std::unique_ptr<Derived>
        {
            return std::make_unique<Derived>(std::forward(args)...);
        }
    };
} // namespace archive::ast

#endif // ARCHIVE_AST_EXPR_EXPR_HPP
