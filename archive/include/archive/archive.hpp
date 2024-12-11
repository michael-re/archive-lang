#pragma once

#ifndef ARCHIVE_ARCHIVE_HPP
#define ARCHIVE_ARCHIVE_HPP

// common
#include "archive/common/alias.hpp"
#include "archive/common/assert.hpp"
#include "archive/common/except.hpp"
#include "archive/common/excode.hpp"
#include "archive/common/fatal.hpp"

// frontend
#include "archive/frontend/location.hpp"
#include "archive/frontend/token.hpp"

namespace archive
{
    [[nodiscard]] auto run(const int argc, const char* argv[]) -> int;
} // namespace archive

#endif // ARCHIVE_ARCHIVE_HPP
