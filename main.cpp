#include <cstdio>
#include <cstdlib>

#include "add.hpp"
#include "add.h"

int main(int argc, char **argv)
{
    // dummy code to get rid of unused parameter warning
    (void)argv;
    (void)argc;

    std::printf("CXX code: 1 + 2 is %d\n\r", add(1, 2));        // CPP code
    std::printf("C   code: 1 + 2 is %d\n\r", add_c_code(1, 2)); // C   code

    return EXIT_SUCCESS;
}