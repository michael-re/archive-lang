#include "archive/ast/expr/impl/char.hpp"

using namespace archive;
using namespace archive::ast;

CharExpr::CharExpr(Token literal)
    : m_value  (0x0),
      m_literal(std::move(literal))
{
    FATAL("todo: validate char literal token");
}

auto CharExpr::token() const -> const Token&
{
    return m_literal;
}

auto CharExpr::value() const -> char
{
    return m_value;
}
