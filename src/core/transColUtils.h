#pragma once


#include <string.h>
#include <ctype.h>

#include "transColor.h"


void HEXmerge(RGB_Hex rgbh, char* comb)
{
  strcat(comb, rgbh.R);
  strcat(comb, rgbh.G);
  strcat(comb, rgbh.B);
}

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
  printf("Converted HSL: %d | %4.2lf | %4.2lf\n", hsl.H, hsl.S, hsl.L);
}