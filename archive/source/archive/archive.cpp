#include <fstream>
#include <filesystem>

#include "archive/archive.hpp"

using namespace archive;

auto archive::run(std::string filename) -> int
{
    if (!std::filesystem::exists(filename))
    {
        fmt::println(std::cerr, "\nerror: failed to find archive file: `{}`\n", filename);
        return exit_code::io_error;
    }

    auto file = std::ifstream(filename, std::ifstream::binary | std::ifstream::in);
    if (!file.is_open())
    {
        fmt::println(std::cerr, "\nerror: i/o error opening archive file: `{}`", filename);
        return exit_code::io_error;
    }

    // TODO: implement parse -> resolve -> compile/interpret
    auto scanner = frontend::Scanner(filename, fmt::to_string(file.rdbuf()));
    auto token   = scanner.scan();

    while (token != frontend::Token::Type::EndOfFile)
    {
        fmt::println(std::cout, "{}", token.lexeme());
        token = scanner.scan();
    }

    return exit_code::success;
}

auto archive::run(const int argc, const char* argv[]) -> int
{
    try
    {
        if (argc != 2)
        {
            fmt::println(std::cerr, "\nusage: ./arc <file>\n");
            return exit_code::usage;
        }

        return run(argv[1]);
    }
    catch (const Exception& e)
    {
        static constexpr auto header = "==================================";
        fmt::println(std::cerr, "\n{}\n{}\n{}\n", header, e.what(), header);
        return exit_code::failure;
    }
    catch (const std::exception& e)
    {
        static constexpr auto header = "====== caught std exception ======";
        fmt::println(std::cerr, "\n{}\n{}\n{}\n", header, e.what(), header);
        return exit_code::failure;
    }
    catch (...)
    {
        static constexpr auto header  = "==== caught unknown exception ====";
        static constexpr auto message = "     ????????????????????????     ";
        fmt::println(std::cerr, "\n{}\n{}\n{}\n", header, message, header);
        return exit_code::failure;
    }
}
