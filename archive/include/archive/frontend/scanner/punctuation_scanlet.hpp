#pragma once

#ifndef ARCHIVE_FRONTEND_SCANNER_PUNCTUATION_SCANLET_HPP
#define ARCHIVE_FRONTEND_SCANNER_PUNCTUATION_SCANLET_HPP

#include "archive/frontend/scanner/scanlet.hpp"

namespace archive::frontend::detail::scanner
{
    class PunctuationScanlet final : public Scanlet
    {
    public:
        [[nodiscard]] virtual auto candidate(Source&) const -> bool  override;
        [[nodiscard]] virtual auto scan     (Source&) const -> Token override;
    };
} // namespace archive::frontend::detail::scanner

#endif // ARCHIVE_FRONTEND_SCANNER_PUNCTUATION_SCANLET_HPP
