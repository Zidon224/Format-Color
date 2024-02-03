//Functions for handling input / output files




#pragma once




#include <iostream>
#include <fstream>
#include <string>
#include "debug.h"



//#define fileDebug





static void ReadInputFile(std::string fPath)
{
    std::string fileData;
    std::ifstream InputFile(fPath);
    if(!InputFile) Err("File not found!");
    if(!InputFile.good()) Err("Failed to read the file!");
    if(InputFile.peek() == std::ifstream::traits_type::eof()) Err("File cannot be empty!");
    while (getline(InputFile, fileData)) std::cout << fileData << "\n";
    InputFile.close();
}
