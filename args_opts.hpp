//This file contains the commands, arguments and the functions used for color conversion.

#pragma once


#include <iostream>
#include <fstream>

#include "debug.h"
#include "showCLInfo.h"
#include "ext_deps/clipp.h"
#include "file_utils.h"
#include "CLI_Proc.h"

//#define CLIdebug
#define DevMode

#ifdef DevMode
    #include "conv_tests.h"
#endif


#define Ver "1.0.0"


std::string inFile; //For input color array from file
std::string outFile; //For exporting the converted color array into a file
std::string colorFMTIn;
std::string colorFMTout;
std::string inColor;
//bool isIcf = true;



//All options of the program
auto CLI_opt = (
    clipp::option("-h", "--help")([]{std::cout << fullHelp;}),
    clipp::option("-v", "--version")([]{std::cout << "Version: " << Ver << "\n";}),
    clipp::option("-sl", "--show_license")([]{std::cout << Licenses;}),
    clipp::option("-inf", "--info")([]{std::cout << FullInfo;}),
    clipp::option("-scf", "--show_color_fmts")([]{std::cout << ColorFMTs;}),
    #ifdef DevMode
        clipp::option("-a")([]{convertTests();}),
    #endif
    clipp::option("-fi", "--file_in") & clipp::value("input file", inFile)([]{
        #ifdef CLIdebug
            std::cout << "[File Input]\n";
        #endif
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
    }),
    //& clipp::value("inColor", inColor)
    clipp::required("-icf:", "--in_color_fmt:") & clipp::value("in color fmt", colorFMTIn) & clipp::value("inColor", inColor)([]{
        #ifdef CLIdebug
            std::cout << "[In Color fmt]\n";
        #endif
        if(colorFMTIn.find("RGB=") != std::string::npos)
        {
            std::cout << "Input Color Format: RGB\n";
            char strSep = ' ';
            stringSplit(inColor, strSep);
            std::cout << "Splited rgb values: \n";
            for(int i = 0; i < MAX_STR_LEN; i++)
            {
                std::cout << "RGB INPUT: " << ICF_str[i] << "\n";
            }
        }
        else if(colorFMTIn.find("HSL=") != std::string::npos)
        {
            std::cout << "Input Color Format: HSL\n";
            
        }
        else if(colorFMTIn.find("HEX=") != std::string::npos)
        {
            std::cout << "Input Color Format: HEX\n";
            
        }
        else
        {
            Err("Unknown input color format!");
            std::cout << "'" << colorFMTIn << "'\n";
        }
        //std::cout << "Color entered: " << inColor << "\n";
    }),
    clipp::required("-ocf:", "--out_color_fmt:") & clipp::value("out color format", colorFMTout)([]{
        #ifdef CLIdebug
            std::cout << "[Output Color Fmt]\n";
        #endif
        if(colorFMTout.find("RGB") != std::string::npos)
            std::cout << "OCF: RGB\n";
        else if(colorFMTout.find("HSL") != std::string::npos)
            std::cout << "OCF: HSL\n";
        else if(colorFMTout.find("HEX") != std::string::npos)
            std::cout << "OCF: HEX\n";
        else
        {
            Err("Unknown output color format!");
            std::cout << "'" << colorFMTout << "'\n";
        }
    })
);
