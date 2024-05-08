/*
This header provides API to the transform color library
API is incomplete btw I still have to do a bit more work...
*/

//Original code found at: https://github.com/CodeDrome/colour-converter-c


#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>


//Data types for handling color types
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

/*
- - - - Color validations - - - -
Returns true if color is correct
*/
bool checkRGB_HEX(RGB_Hex rgbh);
bool checkHSL(HSL hsl);

void HEX2RGB(RGB_Hex rgbh, RGB *rgb);
void HEX2HSL(RGB_Hex rgbh, HSL *hsl);
void RGB2HEX(RGB rgb, RGB_Hex *rgbh);
void RGB2HSL(RGB rgb, HSL *hsl);
void HSL2RGB(HSL hsl, RGB *rgb);
void HSL2HEX(HSL hsl, RGB_Hex *rgbh);
void printRGB(RGB rgb);
void printRGBH(RGB_Hex rgbh);
void printHSL(HSL hsl);
