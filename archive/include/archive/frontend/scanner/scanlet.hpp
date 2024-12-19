#pragma once

#ifndef ARCHIVE_FRONTEND_SCANNER_SCANLET_HPP
#define ARCHIVE_FRONTEND_SCANNER_SCANLET_HPP

#include <memory>

#include "archive/frontend/location.hpp"
#include "archive/frontend/source.hpp"
#include "archive/frontend/token.hpp"

namespace archive::frontend::detail::scanner
{
    class Scanlet
    {
    public:
        explicit Scanlet() = default;
        virtual ~Scanlet() = default;

        [[nodiscard]] virtual auto candidate(Source&) const -> bool  = 0;
        [[nodiscard]] virtual auto scan     (Source&) const -> Token = 0;
    };
} // namespace archive::frontend::detail::scanner

#endif // ARCHIVE_FRONTEND_SCANNER_SCANLET_HPP
