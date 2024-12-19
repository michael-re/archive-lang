#pragma once

#ifndef ARCHIVE_FRONTEND_SCANNER_NUMBER_SCANNER_HPP
#define ARCHIVE_FRONTEND_SCANNER_NUMBER_SCANNER_HPP

#include "archive/frontend/scanner/scanner.hpp"

namespace archive::frontend::detail::scanner
{
    class NumberScanner final : public Scanner
    {
    public:
        [[nodiscard]] virtual auto candidate(const Source&) const -> bool  override;
        [[nodiscard]] virtual auto scan     (      Source&) const -> Token override;

    private:
        [[nodiscard]] static auto bin_literal(Source&) -> Token;
        [[nodiscard]] static auto dec_literal(Source&) -> Token;
        [[nodiscard]] static auto hex_literal(Source&) -> Token;

        [[nodiscard]] static auto read_bin_digits(Source&) -> std::string;
        [[nodiscard]] static auto read_dec_digits(Source&) -> std::string;
        [[nodiscard]] static auto read_hex_digits(Source&) -> std::string;

        [[nodiscard]] static auto remove_leading_zeros (std::string) -> std::string;
        [[nodiscard]] static auto remove_trailing_zeros(std::string) -> std::string;
    };
} // namespace archive::frontend::detail::scanner

#endif // ARCHIVE_FRONTEND_SCANNER_NUMBER_SCANNER_HPP
