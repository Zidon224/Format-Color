#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>



typedef struct
{
    unsigned char R;
    unsigned char G;
    unsigned char B;
} RGB;

typedef struct 
{
    char R[3];
    char G[3];
    char B[3];
} RGB_Hex;

typedef struct
{
    int H;
    double S;
    double L;
} HSL;

bool checkRGB_HEX(RGB_Hex rgbh);
bool checkHSL(HSL hsl);

void HEX2RGB(RGB_Hex rgbh, RGB *rgb); //Success
void HEX2HSL(RGB_Hex rgbh, HSL *hsl); //FAILED
void RGB2HEX(RGB rgb, RGB_Hex *rgbh); //Success
void RGB2HSL(RGB rgb, HSL *hsl);      //FAILED
void HSL2RGB(HSL hsl, RGB *rgb);      //FAILED
void HSL2HEX(HSL hsl, RGB_Hex *rgbh); //Forgot to implement
void printRGB(RGB rgb);
void printRGBH(RGB_Hex rgbh);
void printHSL(HSL hsl);
