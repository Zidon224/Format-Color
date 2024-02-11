#include <stdio.h>
#include "core/convert_utils.h"



void convertTests()
{
    printf("==== CONVERSION TESTS ====\n\n");
    RGB rgbin;

    rgbin.R = 255;
    rgbin.G = 48;
    rgbin.B = 100;
    RGB_Hex rgbhout;

    RGB rgbOUT;

    HSL hslout;
    HSL hslout1;
    HSL hslIN;
    //HSL hslIN2;

    hslIN.H = 104;
    hslIN.S = 226;
    hslIN.L = 122;

    RGB_Hex rgbhIN;
    RGB_Hex rgbhOUT;

    /*rgbhIN.R[2] = 'FF';
    rgbhIN.G[2] = '43';
    rgbhIN.G[2] = '00';*/

    //922DFF
    rgbhIN  = (RGB_Hex){.R = "92", .G = "2D", .B = "FF"};

    RGB rgbOut2;

    
    printf("RGB to HEX [Success]\n");
    RGB2HEX(rgbin, &rgbhout);
    printRGBH(rgbhout);
    printf("\n\n");

    printf("RGB to HSL\n");
    RGB2HSL(rgbin, &hslout);
    printHSL(hslout);
    printf("\n\n");

    //Fail

    printf("HEX to RGB [Success]\n");
    HEX2RGB(rgbhIN, &rgbOut2);
    printRGB(rgbOut2);
    printf("\n\n");

    printf("HEX to HSL\n");
    HEX2HSL(rgbhIN, &hslout1);
    printHSL(hslout1);
    printf("\n\n");

    printf("HSL to RGB\n");
    HSL2RGB(hslIN, &rgbOUT);
    printRGB(rgbOUT);
    printf("\n\n");

    printf("HSL to HEX\n");
    HSL2HEX(hslIN, &rgbhOUT);
    printRGBH(rgbhOUT);
    printf("\n\n");
}
