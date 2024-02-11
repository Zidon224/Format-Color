/* - Entry point of the color converter program - */





#include <iostream>
#include "debug.h"
#include "ext_deps/clipp.h"
#include "args_opts.hpp"
#include "core/convert_utils.h"





int main(int argc, char *argv[])
{
    #ifdef _WIN32
        SetTerminal(); //Setting up the terminal in order to use ansi escape codes for handling text colors in the terminal on windows.
    #endif
    if(argc == 1)
    {
        Err("Atleast 1 argument is required!");
    }
    else if(clipp::parse(argc, argv, CLI_opt))
    {
        std::cout << "Color converter\n";
    }
    else
    {
        Err("Input and output color format must be specified!");
    }

    //Things are working pretty nicely atm :D
    //This is a very simple example of color format conversion I tested out
    //To do: 
    //- more color conversion tests
    //- get assigned values from the CLI parameters into the conversion functions
}
