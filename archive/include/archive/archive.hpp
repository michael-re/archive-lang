#pragma once

#ifndef ARCHIVE_ARCHIVE_HPP
#define ARCHIVE_ARCHIVE_HPP

// common
#include "archive/common/alias.hpp"
#include "archive/common/assert.hpp"
#include "archive/common/except.hpp"
#include "archive/common/excode.hpp"
#include "archive/common/fatal.hpp"
#include "archive/common/format.hpp"
#include "archive/common/utility.hpp"

// frontend
#include "archive/frontend/location.hpp"
#include "archive/frontend/scanner.hpp"
#include "archive/frontend/source.hpp"
#include "archive/frontend/token.hpp"

namespace archive
{
    [[nodiscard]] auto run(std::string filename)               -> int;
    [[nodiscard]] auto run(const int argc, const char* argv[]) -> int;
} // namespace archive

#endif // ARCHIVE_ARCHIVE_HPP
