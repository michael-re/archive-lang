#pragma once

#ifndef ARCHIVE_AST_STMT_FORWARD_HPP
#define ARCHIVE_AST_STMT_FORWARD_HPP

#include <memory>
#include <vector>

#include "archive/common/alias.hpp"
#include "archive/common/assert.hpp"

namespace archive::ast
{
    class Stmt;

    using stmt_ptr = std::unique_ptr<Stmt>;
    using stmt_vec = std::vector<stmt_ptr>;
} // namespace archive::ast

#endif // ARCHIVE_AST_STMT_FORWARD_HPP
