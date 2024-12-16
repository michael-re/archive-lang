#include "archive/ast/expr/impl/integer.hpp"

using namespace archive;
using namespace archive::ast;

IntegerExpr::IntegerExpr(Token literal)
    : m_literal(std::move(literal))
{
    FATAL("todo: validate integer literal token");
}

auto IntegerExpr::token() const -> const Token&
{
    return m_literal;
}

auto IntegerExpr::value() const -> const std::string&
{
    return token().lexeme();
}
