#include "archive/frontend/scanner/number_scanlet.hpp"
#include "archive/common/utility.hpp"
#include "archive/common/assert.hpp"
#include "archive/common/format.hpp"

using namespace archive;
using namespace archive::frontend;
using namespace archive::frontend::detail::scanner;

auto NumberScanlet::candidate(Source& source) const -> bool
{
    return source.is_digit();
}

auto NumberScanlet::scan(Source& source) const -> Token
{
    ASSERT(candidate(source), "invalid number literal candidate");
    if (source.peek("0b") || source.peek("0B")) return bin_num(source);
    if (source.peek("0x") || source.peek("0X")) return hex_num(source);
    return dec_num(source);
}

auto NumberScanlet::bin_num(Source& source) -> Token
{
    static constexpr auto prefix     = std::string_view("0b");
    static constexpr auto min_digits = prefix.size();
    static constexpr auto max_digits = 64 + min_digits;

    const auto location = source.location();
    ASSERT(source.consume("0b") || source.consume("0B"), "invalid binary literal candidate");

    auto number = std::string(prefix) + remove_leading_zeros(read_bin_digits(source));
    auto type   = Token::Type::IntegerLiteral;

    if (number.size() == min_digits)
    {
        number = "expect at least one valid digit in binary literal";
        type   = Token::Type::Error;
    }
    else if (number.size() > max_digits)
    {
        number  = "too many digits in binary literal: '" + number + "'";
        type    = Token::Type::Error;
    }

    return { type, location, std::move(number) };
}

auto NumberScanlet::dec_num(Source& source) -> Token
{
    const auto location  = source.location();
    ASSERT(source.is_dec_digit(), "invalid decimal number candidate");

    auto number = remove_leading_zeros(read_dec_digits(source));
    auto type   = Token::Type::IntegerLiteral;

    if (source.consume('.'))
    {
        type = Token::Type::FloatLiteral;
        number +=  '.' + remove_trailing_zeros(read_dec_digits(source) + '0');
    }

    if (source.consume('e') || source.consume('E'))
    {
        type = Token::Type::FloatLiteral;
        number += source.consume('+') ? "e+" :
                  source.consume('-') ? "e-" : "e+";
        number += remove_trailing_zeros(read_dec_digits(source));
        if (!utility::is_dec_digit(number.back()))
        {
            number = "decimal floating point number missing exponent value";
            type   = Token::Type::Error;
        }
    }

    try
    {
        if (type == Token::Type::IntegerLiteral) utility::ignore(std::stoull(number));
        if (type == Token::Type::FloatLiteral)   utility::ignore(std::stold(number));
    }
    catch (const std::out_of_range&)
    {
        type   = Token::Type::Error;
        number = "decimal literal too large";
    }
    catch (const std::exception& e)
    {
        static constexpr auto header = "=== fatal error converting decimal literal ===";
        FATAL(fmt::to_string("\n{}\n\n{}\n\n{}\n", header, e.what(), header));
    }
    catch (...)
    {
        FATAL("unknown fatal error converting decimal literal");
    }

    return { type, location, std::move(number) };
}

auto NumberScanlet::hex_num(Source& source) -> Token
{
    static constexpr auto prefix     = std::string_view("0x");
    static constexpr auto min_digits = prefix.size();
    static constexpr auto max_digits = 16 + min_digits;

    const auto location = source.location();
    ASSERT(source.consume("0x") || source.consume("0X"), "invalid hex literal candidate");

    auto number = std::string(prefix) + remove_leading_zeros(read_hex_digits(source));
    auto type   = Token::Type::IntegerLiteral;

    if (number.size() == min_digits)
    {
        number = "expect at least one valid digit in hex literal";
        type   = Token::Type::Error;
    }
    else if (number.size() > max_digits)
    {
        number  = "too many digits in hex literal: '" + number + "'";
        type    = Token::Type::Error;
    }

    return { type, location, std::move(number) };
}

auto NumberScanlet::read_bin_digits(Source& source) -> std::string
{
    auto digits = std::string();
    while (source.peek('_') || source.is_bin_digit())
        if (const auto c = source.consume(); c != '_')
            digits.push_back(utility::to_lower(*c));
    return digits;
}

auto NumberScanlet::read_dec_digits(Source& source) -> std::string
{
    auto digits = std::string();
    while (source.peek('_') || source.is_dec_digit())
        if (const auto c = source.consume(); c != '_')
            digits.push_back(utility::to_lower(*c));
    return digits;
}

auto NumberScanlet::read_hex_digits(Source& source) -> std::string
{
    auto digits = std::string();
    while (source.peek('_') || source.is_hex_digit())
        if (const auto c = source.consume(); c != '_')
            digits.push_back(utility::to_lower(*c));
    return digits;
}

auto NumberScanlet::remove_leading_zeros(std::string number) -> std::string
{
    while (number.size() >= 2 && number.front() == '0')
        number.erase(number.begin());
    return number;
}

auto NumberScanlet::remove_trailing_zeros(std::string number) -> std::string
{
    while (number.size() >= 2 && number.front() == '0')
        number.erase(number.begin());
    return number;
}
