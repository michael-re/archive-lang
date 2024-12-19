#include "archive/frontend/scanner.hpp"
#include "archive/common/utility.hpp"

#include "archive/frontend/scanner/identifier_scanlet.hpp"
#include "archive/frontend/scanner/punctuation_scanlet.hpp"
#include "archive/frontend/scanner/whitespace_scanlet.hpp"

using namespace archive;
using namespace archive::frontend;
using namespace archive::frontend::detail::scanner;

Scanner::Scanner(std::string filename, std::string source)
    : m_source     (std::make_unique<Source>(std::move(filename), std::move(source))),
      m_identifier (std::make_unique<IdentifierScanlet>()),
      m_punctuation(std::make_unique<PunctuationScanlet>()),
      m_whitespace (std::make_unique<WhitespaceScanlet>())
{
}

auto Scanner::source() const -> const Source&
{
    return *m_source;
}

auto Scanner::scan() -> Token
{
    auto& source = *m_source;
    if (m_whitespace->candidate(source)) utility::ignore(m_whitespace->scan(source));
    if (m_identifier->candidate(source)) return m_identifier->scan(source);
    return m_punctuation->scan(source);
}
