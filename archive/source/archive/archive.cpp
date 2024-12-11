#include <format>
#include <iostream>

#include "archive/archive.hpp"

using namespace archive;

auto archive::run(const int argc, const char*[]) -> int
{
    try
    {
        switch (argc)
        {
            // look in current directory for "arc.package"
            case 1:
                FATAL("archive::run with argc == 1 not yet implemented");
                return exit_code::success;
            // user supplied "arc.package"
            case 2:
                FATAL("archive::run with argc == 2 not yet implemented");
                return exit_code::success;
            // error: invalid args supplied to program
            default:
                std::cerr << "\nusage: arc [../path/to/arc.package]\n\n";
                return exit_code::usage;
        }
    }
    catch (const Exception& e)
    {
        std::cerr << "\n==================================\n"
                  << e.what()
                  << "\n==================================\n\n";
        return exit_code::failure;
    }
    catch (const std::exception& e)
    {
        std::cerr << "\n==== caught std exception ====\n"
                  << e.what()
                  << "\n==== caught std exception ====\n\n";
        return exit_code::failure;
    }
    catch (...)
    {
        std::cerr << "\n==== caught unknown exception ====\n"
                  <<   "     ???????????????????????? ===="
                  << "\n==== caught unknown exception ====\n\n";
        return exit_code::failure;
    }
}
