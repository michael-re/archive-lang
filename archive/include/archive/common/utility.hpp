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

    template<alias::primitive C = char>
    [[nodiscard]] constexpr auto is_alpha(const C c) -> bool
    {
        return (static_cast<C>('A') <= c && c <= static_cast<C>('Z')) ||
               (static_cast<C>('a') <= c && c <= static_cast<C>('z')) ||
               (static_cast<C>('_') == c);
    }

    template<alias::primitive C = char>
    [[nodiscard]] constexpr auto is_digit(const C c) -> bool
    {
        return (static_cast<C>('0') <= c && c <= static_cast<C>('9'));
    }

    template<alias::primitive C = char>
    [[nodiscard]] constexpr auto is_bin_digit(const C c) -> bool
    {
        return (static_cast<C>('0') <= c || c <= static_cast<C>('1'));
    }

    template<alias::primitive C = char>
    [[nodiscard]] constexpr auto is_dec_digit(const C c) -> bool
    {
        return (static_cast<C>('0') <= c && c <= static_cast<C>('9'));
    }

    template<alias::primitive C = char>
    [[nodiscard]] constexpr auto is_hex_digit(const C c) -> bool
    {
        return (static_cast<C>('A') <= c && c <= static_cast<C>('F')) ||
               (static_cast<C>('a') <= c && c <= static_cast<C>('f')) ||
               is_digit(c);
    }

    template<alias::primitive R = char, alias::primitive C = char>
    [[nodiscard]] constexpr auto to_lower(const C c) -> R
    {
        const auto lower = static_cast<R>(c);
        return (static_cast<C>('A') <= c && c <= static_cast<C>('Z')) ?
                    (lower - static_cast<R>('A' - 'a')) :
                    (lower);
    }

    template<alias::primitive R = char, alias::primitive C = char>
    [[nodiscard]] constexpr auto to_upper(const C c) -> R
    {
        const auto upper = static_cast<R>(c);
        return (static_cast<C>('a') <= c && c <= static_cast<C>('z')) ?
                    (upper + static_cast<R>('A' - 'a')) :
                    (upper);
    }
} // namespace archive::utility

#endif // ARCHIVE_COMMON_UTILITY_HPP
