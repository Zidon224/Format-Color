#pragma once


#include <string.h>
#include <ctype.h>

#include "transColUtils.h"
#include "transColor.h"
#include "transColor.c"




bool checkHex(char c)
{
  if((c < 48 || c > 57) && (c < 65 || c > 70) && (c > 97 || c > 102))
    return false;
  else
    return true;
}

//Exported
//Be careful do not confuse it with checkHex(char c)
//This function is not exported to the library!
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

//Exported
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

//Exported
bool checkRGB(RGB rgb)
{
  if(rgb.R >= 255 || rgb.G >= 255 || rgb.B >= 255)
    return false;
  else if(rgb.R <= 0 || rgb.G <= 0 || rgb.B <= 0)
    return false;

  return true;
}