#pragma once

#ifndef ARCHIVE_FRONTEND_SOURCE_HPP
#define ARCHIVE_FRONTEND_SOURCE_HPP

#include <string>
#include <optional>

#include "archive/common/alias.hpp"
#include "archive/frontend/location.hpp"

namespace archive::frontend
{
    class Source final
    {
    public:
        explicit Source(std::string filename, std::string source_text);

        [[nodiscard]] auto location() const -> const Location&;
        [[nodiscard]] auto filename() const -> const std::string&;
        [[nodiscard]] auto filetext() const -> const std::string&;
        [[nodiscard]] auto at_end()   const -> bool;

        [[nodiscard]] auto peek()                       const -> std::optional<char>;
        [[nodiscard]] auto peek(const char)             const -> std::optional<char>;
        [[nodiscard]] auto peek(const std::string_view) const -> std::optional<std::string_view>;

        [[nodiscard]] auto advance()                       -> std::optional<char>;
        [[nodiscard]] auto consume()                       -> std::optional<char>;
        [[nodiscard]] auto consume(const char)             -> std::optional<char>;
        [[nodiscard]] auto consume(const std::string_view) -> std::optional<std::string_view>;

    private:
        Location         m_location;
        std::size_t      m_cursor;
        std::string      m_filename;
        std::string      m_source_text;
        std::string_view m_source_view;
    };
} // namespace archive::frontend

#endif // ARCHIVE_FRONTEND_SOURCE_HPP
