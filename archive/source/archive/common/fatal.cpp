#include "archive/common/fatal.hpp"
#include "archive/common/format.hpp"
#include "archive/common/excode.hpp"

using namespace archive;

Fatal::Fatal(const std::string_view     message,
             const std::source_location location) noexcept
    : Exception(), m_location(location)
{
    try
    {
        auto formatted = fmt::to_string("fatal error: {}:{}:{}\n", location.file_name(), location.line(), location.column())
                       + fmt::to_string(" * location: {}:{}\n",    location.line(), location.column())
                       + fmt::to_string(" * function: {}",         location.function_name());

        if (!message.empty())
        {
            formatted += "\n |";
            formatted += "\n | ";

            // insert message
            for (const auto& c : message)
            {
                formatted += c;
                if (c == '\n')
                    formatted += " | ";
            }

            formatted += "\n |";
        }

        // successfully created formatted error message
        this->m_message = std::move(formatted);
    }
    catch (...)
    {
        // something went wrong!!!
        this->m_message.clear();
    }
}

auto Fatal::location() const noexcept -> const std::source_location&
{
    return m_location;
}

auto Fatal::terminate() const noexcept -> void
{
    static constexpr auto header = "==== archive fatal termination ====";
    fmt::println(std::cerr, "\n{}\n{}\n{}\n", header, this->message(), header);
    std::exit(archive::exit_code::failure);
}
