#pragma once

#ifndef ARCHIVE_COMMON_ALIAS_HPP
#define ARCHIVE_COMMON_ALIAS_HPP

#include <limits>
#include <cstddef>
#include <cstdint>
#include <type_traits>

namespace archive::alias
{
    using f32 = float;
    using f64 = double;

    using i8  = std::int8_t;
    using i16 = std::int16_t;
    using i32 = std::int32_t;
    using i64 = std::int64_t;

    using u8  = std::uint8_t;
    using u16 = std::uint16_t;
    using u32 = std::uint32_t;
    using u64 = std::uint64_t;

    using bool_t = bool;
    using byte_t = u8;
    using char_t = char;

    template<typename T>
    concept integral = std::is_integral_v<T>;

    template<typename T>
    concept floating = std::is_floating_point_v<T>;

    template<typename T>
    concept primitive = integral<T> || floating<T>;

    static_assert(sizeof(f32) == sizeof(u32), "f32 must be 32-bits");
    static_assert(sizeof(f64) == sizeof(u64), "f64 must be 64-bits");

    static_assert(std::numeric_limits<f32>::is_iec559, "f32 must be IEEE 754 compliant");
    static_assert(std::numeric_limits<f64>::is_iec559, "f64 must be IEEE 754 compliant");
} // namespace archive::alias

#endif // ARCHIVE_COMMON_ALIAS_HPP
