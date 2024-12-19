#pragma once

#ifndef ARCHIVE_COMMON_UTILITY_HPP
#define ARCHIVE_COMMON_UTILITY_HPP

#include "archive/common/alias.hpp"

namespace archive::utility
{
    template<typename... Args>
    inline constexpr auto ignore(Args&&... args) -> void
    {
        (static_cast<void>(args), ...);
    }

    template<alias::primitive C>
    [[nodiscard]] constexpr auto is_alpha(const C c) -> bool
    {
        return (static_cast<C>('A') <= c && c <= static_cast<C>('Z')) ||
               (static_cast<C>('a') <= c && c <= static_cast<C>('z')) ||
               (static_cast<C>('_') == c);
    }

    template<alias::primitive C>
    [[nodiscard]] constexpr auto is_digit(const C c) -> bool
    {
        return (static_cast<C>('0') <= c && c <= static_cast<C>('9'));
    }
} // namespace archive::utility

#endif // ARCHIVE_COMMON_UTILITY_HPP
