#include "archive/ast/expr/impl/bool.hpp"

using namespace archive;
using namespace archive::ast;

BoolExpr::BoolExpr(Token literal)
    : m_literal(std::move(literal))
{
    FATAL("todo: validate bool literal token");
}

auto BoolExpr::token() const -> const Token&
{
    return m_literal;
}

auto BoolExpr::value() const -> bool
{
    return false;
}
