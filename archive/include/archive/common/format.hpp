#pragma once

#ifndef ARCHIVE_COMMON_FORMAT_HPP
#define ARCHIVE_COMMON_FORMAT_HPP

#include <format>
#include <string>
#include <sstream>
#include <iostream>

namespace archive::fmt
{
    template<typename T>
    [[nodiscard]] inline auto to_string(T&& value) -> std::string
    {
        return (std::ostringstream() << value).str();
    }

    template<typename... Args>
    [[nodiscard]] inline auto to_string(std::format_string<Args...> format,
                                        Args&&...                   args) -> std::string
    {
        return std::format(format, std::forward<Args>(args)...);
    }

    template<typename... Args>
    [[maybe_unused]] inline auto print(std::ostream&               stream,
                                       std::format_string<Args...> format,
                                       Args&&...                   args) -> std::ostream&
    {
        return stream << std::format(format, std::forward<Args>(args)...);
    }

    template<typename... Args>
    [[maybe_unused]] inline auto println(std::ostream&               stream,
                                         std::format_string<Args...> format,
                                         Args&&...                   args) -> std::ostream&
    {
        return stream << std::format(format, std::forward<Args>(args)...) << '\n';
    }
} // namespace archive::fmt

#endif // ARCHIVE_COMMON_FORMAT_HPP
