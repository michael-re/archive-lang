#pragma once

#ifndef ARCHIVE_FRONTEND_SCANNER_HPP
#define ARCHIVE_FRONTEND_SCANNER_HPP

#include "archive/frontend/source.hpp"
#include "archive/frontend/token.hpp"

namespace archive::frontend
{
    class Scanner final
    {
    public:
        explicit Scanner(std::string filename, std::string source);

        [[nodiscard]] auto scan()         -> Token;
        [[nodiscard]] auto source() const -> const Source&;

    private:
        Source m_source;
    };
} // namespace archive::frontend

#endif // ARCHIVE_FRONTEND_SCANNER_HPP
