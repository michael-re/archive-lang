#pragma once

#ifndef ARCHIVE_FRONTEND_SCANNER_WHITESPACE_SCANLET_HPP
#define ARCHIVE_FRONTEND_SCANNER_WHITESPACE_SCANLET_HPP

#include "archive/frontend/scanner/scanlet.hpp"

namespace archive::frontend::detail::scanner
{
    class WhitespaceScanlet final : public Scanlet
    {
    public:
        [[nodiscard]] virtual auto candidate(Source&) const -> bool  override;
        [[nodiscard]] virtual auto scan     (Source&) const -> Token override;

    private:
        [[nodiscard]] static auto is_multiline_comment (Source&) -> bool;
        [[nodiscard]] static auto is_singleline_comment(Source&) -> bool;
        [[nodiscard]] static auto is_nonprintable_char (Source&) -> bool;
    };
} // namespace archive::frontend::detail::scanner

#endif // ARCHIVE_FRONTEND_SCANNER_WHITESPACE_SCANLET_HPP
