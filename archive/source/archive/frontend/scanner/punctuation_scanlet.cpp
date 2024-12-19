#include "archive/frontend/scanner/punctuation_scanlet.hpp"
#include "archive/common/format.hpp"

using namespace archive;
using namespace archive::frontend;
using namespace archive::frontend::detail::scanner;

auto PunctuationScanlet::candidate(Source&) const -> bool
{
    return true;
}

auto PunctuationScanlet::scan(Source& source) const -> Token
{
    const auto location = source.location();
    if (source.at_end())
        return { Token::Type::EndOfFile, location };

    switch (const auto c = *source.consume(); c)
    {
        // single/multi character punctuation
        case ',': return { Token::Type::Comma,         location, "," };
        case ';': return { Token::Type::Semicolon,     location, ";" };
        case '?': return { Token::Type::Question,      location, "?" };
        case '(': return { Token::Type::LeftParen,     location, "(" };
        case ')': return { Token::Type::RightParen,    location, ")" };
        case '[': return { Token::Type::LeftBrace,     location, "[" };
        case ']': return { Token::Type::RightBrace,    location, "]" };
        case '{': return { Token::Type::LeftBracket,   location, "{" };
        case '}': return { Token::Type::RightBracket,  location, "}" };
        case '*': return { Token::Type::Star,          location, "*" };
        case '/': return { Token::Type::Slash,         location, "/" };
        case '#': return { Token::Type::Hash,          location, "#" };
        case '^': return { Token::Type::Caret,         location, "^" };
        case '~': return { Token::Type::Tilde,         location, "~" };

        // single/multi character punctuation
        case '-':
            return source.consume("->")
                 ? Token(Token::Type::Arrow, location, "->")
                 : source.consume('-')
                    ? Token(Token::Type::DoubleMinus, location, "--")
                    : Token(Token::Type::SingleMinus, location, "-");
        case ':':
            return source.consume(':')
                 ? Token(Token::Type::DoubleColon, location, "::")
                 : Token(Token::Type::SingleColon, location, ":");
        case '!':
            return source.consume('=')
                 ? Token(Token::Type::BangEqual, location, "!=")
                 : Token(Token::Type::Bang,      location, "!");
        case '.':
            return source.consume("..")
                 ? Token(Token::Type::ClosedRange, location, "...")
                 : source.consume(".<")
                    ? Token(Token::Type::HalfRange, location, "..<")
                    : Token(Token::Type::Dot,       location, ".");
        case '&':
            return source.consume('&')
                 ? Token(Token::Type::DoubleAmpersand, location, "!=")
                 : Token(Token::Type::SingleAmpersand, location, "!");
        case '%':
            return source.consume('%')
                 ? Token(Token::Type::DoublePercent, location, "%%")
                 : Token(Token::Type::SinglePercent, location, "%");
        case '+':
            return source.consume('+')
                 ? Token(Token::Type::DoublePlus, location, "++")
                 : Token(Token::Type::SinglePlus, location, "+");
        case '<':
            return source.consume('=')
                 ? Token(Token::Type::LessEqual, location, "<=")
                 : source.consume('<')
                    ? Token(Token::Type::DoubleLess, location, "<<")
                    : Token(Token::Type::SingleLess, location, "<");
        case '=':
            return source.consume('=')
                 ? Token(Token::Type::SingleEqual, location, "==")
                 : Token(Token::Type::DoubleEqual, location, "=");
        case '>':
            return source.consume('=')
                 ? Token(Token::Type::GreaterEqual, location, ">=")
                 : source.consume('<')
                    ? Token(Token::Type::DoubleGreater, location, ">>")
                    : Token(Token::Type::SingleGreater, location, "?");
        case '|':
            return source.consume('|')
                ? Token(Token::Type::DoubleVBar, location, "||")
                : Token(Token::Type::SingleVBar, location, "|");

        // error
        default:
            static constexpr auto error = "unexpected character `{}` (0x{:x})";
            return { Token::Type::Error, location, fmt::to_string(error, c, c) };
    }
}
