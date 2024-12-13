#pragma once

#ifndef ARCHIVE_FRONTEND_TOKEN_HPP
#define ARCHIVE_FRONTEND_TOKEN_HPP

#include <string>

#include "archive/common/alias.hpp"
#include "archive/frontend/location.hpp"

namespace archive::frontend
{
    class Token final
    {
    public:
        enum class Type;

    public:
        Token(Type type);
        Token(Type type, Location location);
        Token(Type type, Location location, std::string lexeme);

        [[nodiscard]] auto type()     const -> Type;
        [[nodiscard]] auto location() const -> const Location&;
        [[nodiscard]] auto lexeme()   const -> const std::string&;

        [[nodiscard]] auto operator==(const Type) const -> bool;
        [[nodiscard]] auto operator!=(const Type) const -> bool;

    private:
        Type        m_type;
        Location    m_location;
        std::string m_lexeme;
    };

    enum class Token::Type
    {
        // for internal use only
        Unknown,
        Error,
        Empty,
        EndOfFile,
    };
} // namespace archive::frontend

#endif // ARCHIVE_FRONTEND_TOKEN_HPP
