#include "archive/frontend/lexer.hpp"
#include "archive/common/assert.hpp"
#include "archive/common/utility.hpp"

#include "archive/frontend/scanner/identifier_scanner.hpp"
#include "archive/frontend/scanner/number_scanner.hpp"
#include "archive/frontend/scanner/punctuation_scanner.hpp"
#include "archive/frontend/scanner/whitespace_scanner.hpp"

using namespace archive;
using namespace archive::frontend;
using namespace archive::frontend::detail::scanner;

Lexer::Lexer(std::string filename, std::string source)
    : m_prev_token (Token::Type::Empty),
      m_curr_token (Token::Type::Empty),
      m_next_token (Token::Type::Empty),
      m_source     (std::move(filename), std::move(source)),
      m_identifier (std::make_unique<IdentifierScanner>()),
      m_number     (std::make_unique<NumberScanner>()),
      m_punctuation(std::make_unique<PunctuationScanner>()),
      m_whitespace (std::make_unique<WhitespaceScanner>())
{
    lex();
}

auto Lexer::lex() -> Lexer&
{
    if (m_prev_token != Token::Type::EndOfFile)
    {
        const auto scan = [this]() -> Token
        {
            if (m_whitespace->candidate(m_source)) utility::ignore(m_whitespace->scan(m_source));
            if (m_identifier->candidate(m_source)) return m_identifier->scan(m_source);
            if (m_number->candidate(m_source))     return m_number->scan(m_source);
            return m_punctuation->scan(m_source);
        };

        m_prev_token = std::move(m_curr_token);
        m_curr_token = std::move(m_next_token);
        m_next_token = scan();
    }

    return *this;
}

auto Lexer::advance() -> const Token&
{
    return lex().peek_curr();
}

auto Lexer::consume() -> const Token&
{
    return lex().peek_prev();
}

auto Lexer::peek_prev() const -> const Token&
{
    return m_prev_token;
}

auto Lexer::peek_curr()  const -> const Token&
{
    return m_curr_token;
}

auto Lexer::peek_next() const -> const Token&
{
    return m_next_token;
}
