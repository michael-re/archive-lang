#pragma once

#ifndef ARCHIVE_FRONTEND_SCANNER_PUNCTUATION_SCANNER_HPP
#define ARCHIVE_FRONTEND_SCANNER_PUNCTUATION_SCANNER_HPP

#include "archive/frontend/scanner/scanner.hpp"

namespace archive::frontend::detail::scanner
{
    class PunctuationScanner final : public Scanner
    {
    public:
        [[nodiscard]] virtual auto candidate(const Source&) const -> bool  override;
        [[nodiscard]] virtual auto scan     (      Source&) const -> Token override;
    };
} // namespace archive::frontend::detail::scanner

#endif // ARCHIVE_FRONTEND_SCANNER_PUNCTUATION_SCANNER_HPP
