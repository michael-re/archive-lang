#include "archive/frontend/source.hpp"
#include "archive/common/utility.hpp"

using namespace archive;
using namespace archive::frontend;

Source::Source(std::string filename, std::string source_text)
    : m_location   ({ 1, 1 }),
      m_cursor     (0),
      m_filename   (std::move(filename)),
      m_source_text(std::move(source_text)),
      m_source_view(m_source_text)
{
}

auto Source::location() const -> const Location&
{
    return m_location;
}

auto Source::filename() const -> const std::string&
{
    return m_filename;
}

auto Source::filetext() const -> const std::string&
{
    return m_source_text;
}

auto Source::at_end() const -> bool
{
    return m_cursor >= m_source_view.size();
}

auto Source::is_alpha() const -> bool
{
    return !at_end() && utility::is_alpha(*peek());
}

auto Source::is_digit() const -> bool
{
    return !at_end() && utility::is_digit(*peek());
}

auto Source::is_bin_digit() const -> bool
{
    return !at_end() && utility::is_bin_digit(*peek());
}

auto Source::is_dec_digit() const -> bool
{
    return !at_end() && utility::is_dec_digit(*peek());
}

auto Source::is_hex_digit() const -> bool
{
    return !at_end() && utility::is_hex_digit(*peek());
}

auto Source::peek() const -> std::optional<char>
{
    return at_end()
         ? std::nullopt
         : std::make_optional(m_source_view[m_cursor]);
}

auto Source::peek(const char c) const -> std::optional<char>
{
    const auto value = peek();
    return (value == c)
         ? value
         : std::nullopt;
}

auto Source::peek(const std::string_view s) const -> std::optional<std::string_view>
{
    if (at_end())
        return std::nullopt;

    const auto value = m_source_view.substr(m_cursor, s.size());
    return (value == s)
         ? std::make_optional(value)
         : std::nullopt;
}

auto Source::advance() -> std::optional<char>
{
    const auto current = peek();
    if (current == '\n')
    {
        m_location.line++;
        m_location.column = 0;
    }

    if (current != std::nullopt)
    {
        m_cursor++;
        m_location.column++;
    }

    return peek();
}

auto Source::consume() -> std::optional<char>
{
    const auto current = peek();
    utility::ignore(advance());
    return current;
}

auto Source::consume(const char c) -> std::optional<char>
{
    const auto current = peek(c);
    if (current == c) utility::ignore(advance());
    return current;
}

auto Source::consume(const std::string_view s) -> std::optional<std::string_view>
{
    const auto current  = peek(s);
    const auto iterator = current ? *current : std::string_view("");

    for (const auto& i [[maybe_unused]] : iterator)
        utility::ignore(advance());

    return current;
}
