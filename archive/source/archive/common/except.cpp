#include "archive/common/except.hpp"

using namespace archive;

Exception::Exception(std::string message) noexcept
    : m_message(std::move(message))
{
}

Exception::~Exception() noexcept
{
}

auto Exception::what() const noexcept -> const char*
{
    return message().c_str();
}

auto Exception::message() const noexcept -> const std::string&
{
    return m_message;
}
