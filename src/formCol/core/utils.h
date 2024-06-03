#pragma once


#include <string.h>
#include <ctype.h>


#include "../format_color.h"




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





//Functions with char return type for manual management of the output color after conversion
/*char getRGB(RGB rgb)
{
  char buffer[50];
  sprintf(buffer, "%d %d %d", rgb.R, rgb.G, rgb.B);
  return buffer;
}

char getRGBHex(RGB_Hex rgbh)
{
  char buffer[50];
  sprintf(buffer, "#%s%s%s", rgbh.R, rgbh.G, rgbh.B);
  return buffer;
}

char getHSL(HSL hsl)
{
  char buffer[80];
  sprintf(buffer, "%d %4.2lf %4.2lf", hsl.H, hsl.S, hsl.L);
}*/