#pragma once

#ifndef ARCHIVE_AST_STMT_STMT_HPP
#define ARCHIVE_AST_STMT_STMT_HPP

#include "archive/ast/stmt/forward.hpp"

namespace archive::ast
{
    class Stmt
    {
    public:
        template<typename Derived>
        class Node;

        template<bool IsConst>
        class BaseVisitor;

        using Visitor      = BaseVisitor<false>;
        using ConstVisitor = BaseVisitor<true>;

    public:
        explicit Stmt() = default;
        virtual ~Stmt() = default;

        virtual auto accept(Visitor&)            -> void = 0;
        virtual auto accept(ConstVisitor&) const -> void = 0;
    };

    template<bool IsConst>
    class Stmt::BaseVisitor
    {
    public:
        template<typename T>
        using conditional = std::conditional_t<IsConst, const T, T>;

    public:
        explicit BaseVisitor() = default;
        virtual ~BaseVisitor() = default;

        template<typename Node>
        auto visit(conditional<Node>&) -> void
        {
            FATAL("placeholder method");
        }
    };

    template<typename Derived>
    class Stmt::Node : public Stmt
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

#endif // ARCHIVE_AST_STMT_STMT_HPP
