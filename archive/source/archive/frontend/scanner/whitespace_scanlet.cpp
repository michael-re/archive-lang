#include "archive/frontend/scanner/whitespace_scanlet.hpp"
#include "archive/common/utility.hpp"

using namespace archive;
using namespace archive::frontend;
using namespace archive::frontend::detail::scanner;

auto WhitespaceScanlet::candidate(Source& source) const -> bool
{
    return is_nonprintable_char (source)
        || is_singleline_comment(source)
        || is_multiline_comment (source);
}

auto WhitespaceScanlet::scan(Source& source) const -> Token
{
    while (candidate(source))
    {
        if (is_nonprintable_char(source))
        {
            utility::ignore(source.consume());
        }
        else if (is_singleline_comment(source))
        {
            while (!source.at_end() && !source.consume("\n"))
                utility::ignore(source.consume());
        }
        else if (is_multiline_comment(source))
        {
            while (!source.at_end() && !source.consume("*/"))
                utility::ignore(source.consume());
        }
    }

    return source.at_end()
         ? Token(Token::Type::EndOfFile, source.location())
         : Token(Token::Type::Empty,     source.location());
}

auto WhitespaceScanlet::is_singleline_comment(Source& source) -> bool
{
    return !source.at_end() && source.peek("//");
}

auto WhitespaceScanlet::is_multiline_comment(Source& source) -> bool
{
    return !source.at_end() && source.peek("/*");
}

auto WhitespaceScanlet::is_nonprintable_char(Source& source) -> bool
{
    return !source.at_end() && source.peek() <= 0x20;
}