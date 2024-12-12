#include <fstream>
#include <filesystem>

#include "archive/archive.hpp"

using namespace archive;

auto archive::run(std::string filename) -> int
{
    if (!std::filesystem::exists(filename))
    {
        fmt::println(std::cerr, "\nerror: failed to find arc package: `{}`\n", filename);
        return exit_code::io_error;
    }

    auto file = std::ifstream(filename, std::ifstream::binary | std::ifstream::in);
    if (!file.is_open())
    {
        fmt::println(std::cerr, "\nerror: i/o error opening arc package: `{}`", filename);
        return exit_code::io_error;
    }

    // TODO: implement parse -> resolve -> compile/interpret
    auto buff = fmt::to_string(file.rdbuf());
    FATAL(fmt::to_string("arc package '{}':\n{}", filename, buff));
}

auto archive::run(const int argc, const char* argv[]) -> int
{
    try
    {
        switch (argc)
        {
            case 1: return run("arc.package"); // look in current directory for "arc.package"
            case 2: return run(argv[1]);       // user supplied "arc.package"
            default:                           // error: invalid args supplied to program
                fmt::println(std::cerr, "\nusage: arc [../path/to/arc.package]\n");
                return exit_code::usage;
        }
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
