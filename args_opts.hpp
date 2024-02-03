//This file contains the commands, arguments and the functions used for color conversion.




#include <iostream>
#include <fstream>

#include "debug.h"
#include "showCLInfo.h"
#include "ext_deps/clipp.h"
#include "file_utils.h"



#define Ver "1.0.0"
#define CLIdebug
#define DevMode

std::string inFile; //For input color array from file
std::string outFile; //For exporting the converted color array into a file




//All options of the program
auto CLI_opt = (
    clipp::option("-h", "--help")([]{std::cout << fullHelp;}),
    clipp::option("-v", "--version")([]{std::cout << "Version: " << Ver << "\n";}),
    clipp::option("-sl", "--show_license")([]{std::cout << Licenses;}),
    clipp::option("-scf", "--show_color_fmts")([]{std::cout << ColorFMTs;}),
    clipp::option("-icf", "--in_color_fmt")([]{
        #ifdef CLIdebug
            std::cout << "[In Color fmt]\n";
        #endif
    }),
    clipp::option("-ocf", "--out_color_fmt")([]{
        #ifdef CLIdebug
            std::cout << "[Output Color Fmt]\n";
        #endif
    }),
    clipp::option("-fi", "--file_in") & clipp::value("input file", inFile)([]{
        #ifdef CLIdebug
            std::cout << "[File Input]\n";
        #endif
        std::cout << "Color array input from file: " << inFile << "\n";
        ReadInputFile(inFile);
    }),
    clipp::option("-fo", "--file_out") & clipp::value("out file", outFile)([]{
        #ifdef CLIdebug
            std::cout << "[File output]\n";
            std::cout << "Out file path: " << outFile << "\n";
        #endif
    }),
    clipp::option("-vc", "--view_color")([]{
        #ifdef CLIdebug
            std::cout << "[View Color]\n";
        #endif
    }),
    clipp::option("-cpk", "--color_picker")([]{
        #ifdef CLIdebug
            std::cout << "[Color Picker]\n";
        #endif
    }),
    #ifdef DevMode
    clipp::option("-debug_test")([]{
        Info("Info");
        Warn("Warn");
        Err("Err");
        Success("Succes");
    }),
    #endif
    clipp::option("-ui", "--user_interface")([]{
        #ifdef CLIdebug
            std::cout << "[User Interface]\n";
        #endif
    })
);
