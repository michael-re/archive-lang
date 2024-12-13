#include "archive/frontend/scanner.hpp"
#include "archive/common/utility.hpp"

using namespace archive;
using namespace archive::frontend;

Scanner::Scanner(std::string filename, std::string source)
    : m_source(std::move(filename), std::move(source))
{
}

auto Scanner::source() const -> const Source&
{
    return m_source;
}

auto Scanner::scan() -> Token
{
    return m_source.at_end()
         ? Token(Token::Type::EndOfFile, m_source.location())
         : Token(Token::Type::Unknown, m_source.location(), { *m_source.consume() });
}
