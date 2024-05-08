#pragma once

#include <string.h>
#include <ctype.h>

#include "transColor.h"
#include "HSL_processor.h"


static int CharIndex(char* str, char c)
{
  char *i = strchr(str, c);
  return i != NULL ? i - str : -1;
}

void printRGB(RGB rgb)
{
  printf("Converted RGB: %d | %d | %d\n", rgb.R, rgb.G, rgb.B);
}

void printRGBH(RGB_Hex rgbh)
{
  printf("Converted HEX: #%s%s%s\n", rgbh.R, rgbh.G, rgbh.B);
}

void printHSL(HSL hsl)
{
  printf("Converted HSL: %d | %4.2lf | %4.2lf", hsl.H, hsl.S, hsl.L);
}

void HEXmerge(RGB_Hex rgbh, char* comb)
{
  strcat(comb, rgbh.R);
  strcat(comb, rgbh.G);
  strcat(comb, rgbh.B);
}

//Implementations

bool checkHex(char c)
{
  if((c < 48 || c > 57) && (c < 65 || c > 70) && (c > 97 || c > 102))
    return false;
  else
    return true;
}

bool checkRGB_HEX(RGB_Hex rgbh)
{
  if(strlen(rgbh.R) != 2 || strlen(rgbh.G) != 2 || strlen(rgbh.B) != 2)
    return false;

  char combn[7] = "";

  HEXmerge(rgbh, combn);

  for(int i = 0; i <= 5; i++)
  {
    if(!checkHex(combn[i]))
      return false;
  }
  return false;
}

bool checkHSL(HSL hsl)
{
  if(hsl.H < 0 || hsl.H > 360)
    return false;

  if(hsl.S < 0 || hsl.S > 100)
    return false;

  if(hsl.L < 0 || hsl.L > 100)
    return false;

  return true;
}

void HEX2RGB(RGB_Hex rgbh, RGB *rgb)
{
  char HEX_VAL[] = "0123456789ABCDEF";
  rgb -> R = CharIndex(HEX_VAL, toupper(rgbh.R[1])) + (CharIndex(HEX_VAL, toupper(rgbh.R[0])) * 16);
  rgb -> G = CharIndex(HEX_VAL, toupper(rgbh.G[1])) + (CharIndex(HEX_VAL, toupper(rgbh.G[0])) * 16);
  rgb -> B = CharIndex(HEX_VAL, toupper(rgbh.B[1])) + (CharIndex(HEX_VAL, toupper(rgbh.B[0])) * 16);
}

void RGB2HEX(RGB rgb, RGB_Hex *rgbh)
{
  char HEX_VAL[] = "0123456789ABCDEF";
  int i0, i1;

  i0 = rgb.R / 16;
  i1 = rgb.R - (16 * i0);

  rgbh -> R[0] = HEX_VAL[i0];
  rgbh -> R[1] = HEX_VAL[i1];
  rgbh -> R[2] = '\0';

  i0 = rgb.G / 16;
  i1 = rgb.G - (16 * i0);

  rgbh -> G[0] = HEX_VAL[i0];
  rgbh -> G[1] = HEX_VAL[i1];
  rgbh -> G[2] = '\0';

  i0 = rgb.B / 16;
  i1 = rgb.B - (16 * i0);

  rgbh -> B[0] = HEX_VAL[i0];
  rgbh -> B[1] = HEX_VAL[i1];
  rgbh -> B[2] = '\0';
}

void RGB2HSL(RGB rgb, HSL *hsl)
{
  hsl -> H = (int) procHue(rgb);
  hsl -> S = procSat(rgb, hsl -> L);
  hsl -> L = procLight(rgb);
}

void HEX2HSL(RGB_Hex rgbh, HSL *hsl)
{
  RGB rgb;
  HEX2RGB(rgbh, &rgb);
  RGB2HSL(rgb, hsl);
}

void HSL2RGB(HSL hsl, RGB *rgb)
{
  hsl.L /= 100.0;
  hsl.S /= 100.0;

  if(hsl.S == 0)
  {
    rgb -> R = hsl.L * 255.0;
    rgb -> G = hsl.L * 255.0;
    rgb -> B = hsl.L * 255.0;
  }
  else
  {
    double temp1;

    if(hsl.L < 0.5)
      temp1 = hsl.L * (1.0 + hsl.S);

    else
      temp1 = hsl.L + hsl.S - hsl.L * hsl.S;

    double temp2 = 2.0 * hsl.L - temp1;
    double hue = hsl.H / 360.0;

    double tempR = hue + 0.333;
    double tempG;
    double tempB = hue + 0.333;

    if(tempR < 0.0)
      tempR += 1.0;

    if(tempR > 1.0)
      tempR -= 1.0;


    if(tempG < 0.0)
      tempG += 1.0;

    if(tempG > 1.0)
      tempG -= 1.0;


    if(tempB < 0.0)
      tempB += 1.0;

    if(tempB > 1.0)
      tempB -= 1.0;


    if((6.0 * tempR) < 1.0)
      rgb -> R = round((temp2 + (temp1 - temp2) * 6.0 * tempR) * 255.0);
    else if((2.0 * tempR) < 1.0)
      rgb -> R = round(temp1 * 255.0);
    else if((3.0 * tempR) < 2.0)
      rgb -> R = round((temp2 + (temp1 - temp2) * (0.666 - tempR) * 6.0) * 255.0);
    else
      rgb -> R = round(temp2 * 255.0);


    if((6.0 * tempR) < 1.0)
      rgb -> G = round((temp2 + (temp1 - temp2) * 6.0 * tempG) * 255.0);
    else if((2.0 * tempG) < 1.0)
      rgb -> G = round(temp1 * 255.0);
    else if((3.0 * tempG) < 2.0)
      rgb -> G = round((temp2 + (temp1 - temp2) * (0.666 - tempG) * 6.0) * 255.0);
    else
      rgb -> G = round(temp2 * 255.0);


    if((6.0 * tempB) < 1.0)
      rgb -> B = round((temp2 + (temp1 - temp2) * 6.0 * tempB) * 255.0);
    else if((2.0 * tempB) < 1.0)
      rgb -> B = round(temp1 * 255.0);
    else if((3.0 * tempB) < 2.0)
      rgb -> B = round((temp2 + (temp1 - temp2) * (0.666 - tempB) * 6.0) * 255.0);
    else
      rgb -> B = round(temp2 * 255.0);
  }
}

void HSL2HEX(HSL hsl, RGB_Hex *rgbh)
{
  RGB rgb;
  HSL2RGB(hsl, &rgb);
  RGB2HEX(rgb, rgbh);
}
