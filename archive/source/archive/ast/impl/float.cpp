#include "archive/ast/expr/impl/float.hpp"

using namespace archive;
using namespace archive::ast;

FloatExpr::FloatExpr(Token literal)
    : m_literal(std::move(literal))
{
    FATAL("todo: validate float literal token");
}

auto FloatExpr::token() const -> const Token&
{
    return m_literal;
}

auto FloatExpr::value() const -> const std::string&
{
    return token().lexeme();
}
