#pragma once

#ifndef ARCHIVE_FRONTEND_LEXER_HPP
#define ARCHIVE_FRONTEND_LEXER_HPP

#include <string>
#include <optional>

#include "archive/frontend/scanner.hpp"
#include "archive/frontend/token.hpp"

namespace archive::frontend
{
    class Lexer final
    {
    public:
        explicit Lexer(std::string filename, std::string source);

        auto lex()     -> Lexer&;
        auto advance() -> const Token&;
        auto consume() -> const Token&;

        [[nodiscard]] auto peek_prev() const -> const Token&;
        [[nodiscard]] auto peek_curr() const -> const Token&;
        [[nodiscard]] auto peek_next() const -> const Token&;

    private:
        Scanner              m_scanner;
        std::optional<Token> m_previous;
        std::optional<Token> m_current;
        std::optional<Token> m_next;
    };
} // namespace archive::frontend

#endif // ARCHIVE_FRONTEND_LEXER_HPP
