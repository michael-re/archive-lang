#pragma once

#ifndef ARCHIVE_FRONTEND_LEXER_HPP
#define ARCHIVE_FRONTEND_LEXER_HPP

#include <memory>
#include <string>
#include <optional>

#include "archive/frontend/scanner/scanner.hpp"
#include "archive/frontend/token.hpp"

namespace archive::frontend
{
    class Lexer final
    {
    public:
        using Source  = archive::frontend::Source;
        using Scanner = archive::frontend::detail::scanner::Scanner;

    public:
        explicit Lexer(std::string filename, std::string source);

        auto lex()     -> Lexer&;
        auto advance() -> const Token&;
        auto consume() -> const Token&;

        [[nodiscard]] auto peek_prev() const -> const Token&;
        [[nodiscard]] auto peek_curr() const -> const Token&;
        [[nodiscard]] auto peek_next() const -> const Token&;

    private:
        Token  m_prev_token;
        Token  m_curr_token;
        Token  m_next_token;
        Source m_source;

        std::unique_ptr<Scanner> m_identifier;
        std::unique_ptr<Scanner> m_number;
        std::unique_ptr<Scanner> m_punctuation;
        std::unique_ptr<Scanner> m_whitespace;
    };
} // namespace archive::frontend

#endif // ARCHIVE_FRONTEND_LEXER_HPP
