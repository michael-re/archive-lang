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
        // symbol: punctuation/operators
        SingleAmpersand,    // &
        DoubleAmpersand,    // &&
        Arrow,              // ->
        Bang,               // !
        BangEqual,          // !=
        LeftBrace,          // {
        RightBrace,         // }
        LeftBracket,        // [
        RightBracket,       // ]
        SingleColon,        // :
        DoubleColon,        // ::
        Caret,              // ^
        Comma,              // ,
        Dot,                // .
        ClosedRange,        // ...
        HalfRange,          // ..<
        SingleEqual,        // =
        DoubleEqual,        // ==
        SingleGreater,      // >
        DoubleGreater,      // >>
        GreaterEqual,       // >=
        SingleLess,         // <
        DoubleLess,         // <<
        LessEqual,          // <=
        SingleMinus,        // -
        DoubleMinus,        // --
        LeftParen,          // (
        RightParen,         // )
        Percent,            // %
        SinglePlus,         // +
        DoublePlus,         // ++
        Question,           // ?
        Hash,               // #
        Semicolon,          // ;
        Slash,              // /
        Star,               // *
        Tilde,              // ~
        SingleVBar,         // |
        DoubleVBar,         // ||

        // literals
        Character,
        Float,
        Identifier,
        Integer,
        String,

        // keywords
        As,
        Break,
        Case,
        Class,
        Continue,
        Default,
        Delete,
        Do,
        Else,
        Enum,
        False,
        For,
        Fun,
        If,
        Import,
        Lambda,
        Let,
        Module,
        New,
        Nil,
        Return,
        Switch,
        True,
        Var,
        While,

        // basic data types
        Bool,
        Char,
        Void,

        // signed integer types
        I8,
        I16,
        I32,
        I64,
        I128,
        Isz,

        // unsigned integer types
        U8,
        U16,
        U32,
        U64,
        U128,
        Usz,

        // floating point types
        F16,
        F32,
        F64,
        F80,
        F128,

        // for internal use only
        Unknown,
        Error,
        Empty,
        EndOfFile,
    };
} // namespace archive::frontend

#endif // ARCHIVE_FRONTEND_TOKEN_HPP
