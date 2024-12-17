#include "archive/frontend/lexer.hpp"
#include "archive/common/assert.hpp"

using namespace archive;
using namespace archive::frontend;

Lexer::Lexer(std::string filename, std::string source)
    : m_scanner (std::move(filename), std::move(source)),
      m_previous(std::nullopt),
      m_current (m_scanner.scan()),
      m_next    (m_scanner.scan())
{
}

auto Lexer::lex() -> Lexer&
{
    if (m_previous != Token::Type::EndOfFile)
    {
        m_previous = std::move(m_current);
        m_current  = std::move(m_next);
        m_next     = m_scanner.scan();
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
    ASSERT(m_previous, "trying to access previous token when it does not exist");
    return *m_previous;
}

auto Lexer::peek_curr()  const -> const Token&
{
    ASSERT(m_current, "trying to access current token when it does not exist");
    return *m_current;
}

auto Lexer::peek_next() const -> const Token&
{
    ASSERT(m_next, "trying to access next token when it does not exist");
    return *m_next;
}
