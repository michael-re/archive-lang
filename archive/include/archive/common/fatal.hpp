#pragma once

#ifndef ARCHIVE_COMMON_FATAL_HPP
#define ARCHIVE_COMMON_FATAL_HPP

#include <string_view>
#include <source_location>

#include "archive/common/except.hpp"

namespace archive
{
    class Fatal final : public Exception
    {
    public:
        explicit Fatal(const std::string_view     message  = "",
                       const std::source_location location =
                             std::source_location::current()) noexcept;

        [[nodiscard]] auto location()  const noexcept -> const std::source_location&;
        [[noreturn]]  auto terminate() const noexcept -> void;

    private:
        std::source_location m_location;
    };
} // namespace archive

#endif // ARCHIVE_COMMON_FATAL_HPP
