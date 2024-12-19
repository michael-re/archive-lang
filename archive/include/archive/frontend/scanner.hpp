#pragma once

#ifndef ARCHIVE_FRONTEND_SCANNER_HPP
#define ARCHIVE_FRONTEND_SCANNER_HPP

#include <memory>

#include "archive/frontend/scanner/scanlet.hpp"
#include "archive/frontend/source.hpp"

namespace archive::frontend
{
    class Scanner final
    {
    public:
        using Scanlet = archive::frontend::detail::scanner::Scanlet;
        using Source  = archive::frontend::Source;

    public:
        explicit Scanner(std::string filename, std::string source);

        [[nodiscard]] auto scan()         -> Token;
        [[nodiscard]] auto source() const -> const Source&;

    private:
        std::unique_ptr<Source>  m_source;
        std::unique_ptr<Scanlet> m_whitespace;
    };
} // namespace archive::frontend

#endif // ARCHIVE_FRONTEND_SCANNER_HPP
