#pragma once


#include <iostream>
#include <string>

#include "args_opts.hpp"
#include "core/convert_utils.h"



//These splitting algorithms will be used with the RGB and HSL color input.

#define MAX_STR_LEN 3

HSL procHSL;
RGB_Hex rgbhInput;


std::string ICF_str[MAX_STR_LEN];

static int getLen(std::string strParam)
{
    int len = 0;
    for(int i=0; strParam[i] != '\0'; i++)
        len++;

    return len;
}

static void stringSplit(std::string inpStr, char separator)
{
    int InitIndex = 0, startInxed = 0, endIndex = 0, i = 0;

    while(i <= getLen(inpStr))
    {
        if(inpStr[i] == separator || i == getLen(inpStr))
        {
            endIndex = i;
            std::string subStr = "";
            subStr.append(inpStr, startInxed, endIndex - startInxed);
            ICF_str[InitIndex] = subStr;
            InitIndex += 1;
            startInxed = endIndex + 1;
        }
        i++;
    }
}

static void CheckInOut(std::string inParam, std::string outParam)
{
    //RGB -> HEX
    if(inParam == "RGB=" && outParam == "HEX")
    {
        std::cout << "Check icf: RGB -> HEX\n";
    }
    //RGB -> HSL
    else if(inParam == "RGB=" && outParam == "HSL")
    {
        std::cout << "Check ICF OCF: RGB -> HSL\n";
    }
    //HSL -> RGB
    else if(inParam == "HSL=" && outParam == "RGB")
    {
        std::cout << "Check ICF OCF: HSL -> RGB\n";
    }
    //HSL -> HEX
    else if(inParam == "HSL=" && outParam == "HEX")
    {
        std::cout << "Check ICF OCF: HSL -> HEX\n";
    }
    //HEX -> HSL
    else if(inParam == "HEX=" && outParam == "HSL")
    {
        std::cout << "Check ICF OCF: HEX -> HSL\n";
        //rgbhInput = inColor;
        //HEX2HSL(rgbhInput, &procHSL);
        //Defenetly WRONG!!!
        //Need to find an actual way to do this at first...
    }
    //HEX -> RGB
    else if(inParam == "HEX=" && outParam == "RGB")
    {
        std::cout << "Check ICF OCF: HEX -> RGB\n";
    }
}
