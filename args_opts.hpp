//This file contains the commands, arguments and the functions used for color conversion.

#pragma once


#include <iostream>
#include <fstream>

#include "debug.h"
#include "showCLInfo.h"
#include "ext_deps/clipp.h"
#include "file_utils.h"



#define Ver "1.0.0"
//#define CLIdebug
#define DevMode

std::string inFile; //For input color array from file
std::string outFile; //For exporting the converted color array into a file
std::string colorFMTIn;
std::string colorFMTout;




//All options of the program
auto CLI_opt = (
    clipp::option("-h", "--help")([]{std::cout << fullHelp;}),
    clipp::option("-v", "--version")([]{std::cout << "Version: " << Ver << "\n";}),
    clipp::option("-sl", "--show_license")([]{std::cout << Licenses;}),
    clipp::option("-scf", "--show_color_fmts")([]{std::cout << ColorFMTs;}),
    (clipp::required("-icf:", "--in_color_fmt:") & clipp::value("in color fmt", colorFMTIn)([]{
        #ifdef CLIdebug
            std::cout << "[In Color fmt]\n";
        #endif
        if(colorFMTIn.find("RGB") != std::string::npos)
            std::cout << "Input Color Format: RGB\n";
        else if(colorFMTIn.find("HSL") != std::string::npos)
            std::cout << "Input Color Format: HSL\n";
        else if(colorFMTIn.find("HEX") != std::string::npos)
            std::cout << "Input Color Format: HEX\n";
        //Failed to return error when string is empty
        //else if(!colorFMTIn.size())
            //Err("You must enter a input color format!");
            //Err("Unknown input color format!");
        else
        {
            Err("Unknown input color format!");
            std::cout << "'" << colorFMTIn << "'\n";
        }
    })),
    (clipp::required("-ocf:", "--out_color_fmt:") & clipp::value("out color format", colorFMTout)([]{
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
    })),
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
    })
);
