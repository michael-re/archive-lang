#pragma once

#ifndef ARCHIVE_AST_EXPR_FORWARD_HPP
#define ARCHIVE_AST_EXPR_FORWARD_HPP

#include <memory>
#include <vector>

#include "archive/common/alias.hpp"
#include "archive/common/assert.hpp"

namespace archive::ast
{
    class Expr;
    class BinaryExpr;
    class UnaryExpr;

    using expr_ptr = std::unique_ptr<Expr>;
    using expr_vec = std::vector<expr_ptr>;
} // namespace archive::ast

#endif // ARCHIVE_AST_EXPR_FORWARD_HPP
