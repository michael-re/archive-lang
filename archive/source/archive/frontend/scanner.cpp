#include "archive/frontend/scanner.hpp"
#include "archive/common/utility.hpp"

#include "archive/frontend/scanner/whitespace_scanlet.hpp"
#include "archive/frontend/scanner/punctuation_scanlet.hpp"

using namespace archive;
using namespace archive::frontend;
using namespace archive::frontend::detail::scanner;

Scanner::Scanner(std::string filename, std::string source)
    : m_source     (std::make_unique<Source>(std::move(filename), std::move(source))),
      m_whitespace (std::make_unique<WhitespaceScanlet>()),
      m_punctuation(std::make_unique<PunctuationScanlet>())
{
}

auto Scanner::source() const -> const Source&
{
    return *m_source;
}

auto Scanner::scan() -> Token
{
    if (m_whitespace->candidate(*m_source))
        utility::ignore(m_whitespace->scan(*m_source));

    return m_punctuation->scan(*m_source);
}
