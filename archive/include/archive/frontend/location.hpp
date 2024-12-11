#pragma once

#ifndef ARCHIVE_FRONTEND_LOCATION_HPP
#define ARCHIVE_FRONTEND_LOCATION_HPP

#include "archive/common/alias.hpp"

namespace archive::frontend
{
    struct Location final
    {
        std::uint64_t line;
        std::uint64_t column;
    };
} // namespace archive::frontend

#endif // ARCHIVE_FRONTEND_LOCATION_HPP
