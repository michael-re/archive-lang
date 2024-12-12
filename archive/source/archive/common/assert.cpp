#include "archive/common/assert.hpp"
#include "archive/common/excode.hpp"
#include "archive/common/format.hpp"

using namespace archive;
using namespace archive::assert;

auto assert::error(const std::string_view     expression,
                   const std::string_view     message,
                   const std::source_location location) -> Fatal
{
    const auto reason = expression.empty() ? "(empty assert expression)" : expression;
    return message.empty()
         ? Fatal(fmt::to_string("assertion failed: {}", reason), location)
         : Fatal(fmt::to_string("assertion failed: {}\n\n{}", reason, message), location);
}

auto assert::terminate(const std::string_view     expression,
                       const std::string_view     message,
                       const std::source_location location) -> void
{
    error(expression, message, location).terminate();
}
