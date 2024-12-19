#pragma once

#ifndef ARCHIVE_FRONTEND_SCANNER_IDENTIFIER_SCANNER_HPP
#define ARCHIVE_FRONTEND_SCANNER_IDENTIFIER_SCANNER_HPP

#include "archive/frontend/scanner/scanner.hpp"

namespace archive::frontend::detail::scanner
{
    class IdentifierScanner final : public Scanner
    {
    public:
        [[nodiscard]] virtual auto candidate(const Source&) const -> bool  override;
        [[nodiscard]] virtual auto scan     (      Source&) const -> Token override;

    private:
        [[nodiscard]] static auto identifier_name(Source&)          -> std::string;
        [[nodiscard]] static auto identifier_type(std::string_view) -> Token::Type;
    };
} // namespace archive::frontend::detail::scanner

#endif // ARCHIVE_FRONTEND_SCANNER_IDENTIFIER_SCANNER_HPP
