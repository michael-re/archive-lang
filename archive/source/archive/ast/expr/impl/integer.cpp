#include "archive/ast/expr/impl/integer.hpp"

using namespace archive;
using namespace archive::ast;

IntegerExpr::IntegerExpr(Token literal)
    : m_value  (0x0),
      m_literal(std::move(literal))
{
    FATAL("todo: validate integer literal token");
}

auto IntegerExpr::token() const -> const Token&
{
    return m_literal;
}

auto IntegerExpr::value() const -> std::uint64_t
{
    return m_value;
}
