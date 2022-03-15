/*
** EPITECH PROJECT, 2021
** B-MAT_205IQ
** File description:
** Start
*/

#include <cstring>
#include "Iq.hpp"
#include "Error.hpp"

static int DisplayHelp(void) noexcept
{
    std::cout << "USAGE" << std::endl;
    std::cout << "    ./205IQ u s [IQ1] [IQ2]\n" << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "  u\tmean" << std::endl;
    std::cout << "  s\tstandard deviation" << std::endl;
    std::cout << "  IQ1\tminimum IQ" << std::endl;
    std::cout << "  IQ2\tmaximum IQ" << std::endl;
    return SUCCESS;
}

int start(int const ac, char const **av)
{
    int ret = SUCCESS;

    if (ac == 2 && strcmp(av[1], "-h") == 0)
        return DisplayHelp();
    try {
        IQ iq(ac, av);
        if (ac == 3)
            iq.NormalDistrib();
        else if (ac == 4)
            iq.ComputeLower();
        else
            iq.ComputeBetween();
    }
    catch (Error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        ret = ERROR;
    }
    catch (...) {}
    return ret;
}