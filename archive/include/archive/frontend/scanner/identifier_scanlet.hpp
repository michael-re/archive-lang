#ifndef ARCHIVE_FRONTEND_SCANNER_IDENTIFIER_SCANLET_HPP
#define ARCHIVE_FRONTEND_SCANNER_IDENTIFIER_SCANLET_HPP

#include "archive/frontend/scanner/scanlet.hpp"

namespace archive::frontend::detail::scanner
{
    class IdentifierScanlet final : public Scanlet
    {
    public:
        [[nodiscard]] virtual auto candidate(Source&) const -> bool  override;
        [[nodiscard]] virtual auto scan     (Source&) const -> Token override;

    private:
        [[nodiscard]] static auto identifier_name(Source&)          -> std::string;
        [[nodiscard]] static auto identifier_type(std::string_view) -> Token::Type;
    };
} // namespace archive::frontend::detail::scanner

#endif // ARCHIVE_FRONTEND_SCANNER_IDENTIFIER_SCANLET_HPP
