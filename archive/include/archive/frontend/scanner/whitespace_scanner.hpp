#pragma once

#ifndef ARCHIVE_FRONTEND_SCANNER_WHITESPACE_SCANNER_HPP
#define ARCHIVE_FRONTEND_SCANNER_WHITESPACE_SCANNER_HPP

#include "archive/frontend/scanner/scanner.hpp"

namespace archive::frontend::detail::scanner
{
    class WhitespaceScanner final : public Scanner
    {
    public:
        [[nodiscard]] virtual auto candidate(const Source&) const -> bool  override;
        [[nodiscard]] virtual auto scan     (      Source&) const -> Token override;

    private:
        [[nodiscard]] static auto is_multiline_comment (const Source&) -> bool;
        [[nodiscard]] static auto is_singleline_comment(const Source&) -> bool;
        [[nodiscard]] static auto is_nonprintable_char (const Source&) -> bool;
    };
} // namespace archive::frontend::detail::scanner

#endif // ARCHIVE_FRONTEND_SCANNER_WHITESPACE_SCANNER_HPP
