#pragma once


#include <iostream>
#include <string>



//These splitting algorithms will be used with the RGB and HSL color input.

#define MAX_STR_LEN 3


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
