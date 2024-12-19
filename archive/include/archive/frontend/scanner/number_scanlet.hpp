#pragma once

#ifndef ARCHIVE_FRONTEND_SCANNER_NUMBER_SCANLET_HPP
#define ARCHIVE_FRONTEND_SCANNER_NUMBER_SCANLET_HPP

#include "archive/frontend/scanner/scanlet.hpp"

namespace archive::frontend::detail::scanner
{
    class NumberScanlet final : public Scanlet
    {
    public:
        [[nodiscard]] virtual auto candidate(Source&) const -> bool  override;
        [[nodiscard]] virtual auto scan     (Source&) const -> Token override;

    private:
        [[nodiscard]] static auto bin_num(Source&) -> Token;
        [[nodiscard]] static auto dec_num(Source&) -> Token;
        [[nodiscard]] static auto hex_num(Source&) -> Token;

        [[nodiscard]] static auto read_bin_digits(Source&) -> std::string;
        [[nodiscard]] static auto read_dec_digits(Source&) -> std::string;
        [[nodiscard]] static auto read_hex_digits(Source&) -> std::string;

        [[nodiscard]] static auto remove_leading_zeros (std::string) -> std::string;
        [[nodiscard]] static auto remove_trailing_zeros(std::string) -> std::string;
    };
} // namespace archive::frontend::detail::scanner

#endif // ARCHIVE_FRONTEND_SCANNER_NUMBER_SCANLET_HPP
