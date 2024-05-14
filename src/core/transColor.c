#pragma once

#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "transColor.h"
#include "transColUtils.h"
#include "HSL_processor.c"
#include "color_validations.c"






//Implementations


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
  hsl -> L = procLight(rgb);
  hsl -> S = procSat(rgb, hsl -> L);
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
    rgb->R = hsl.L * 255.0;
    rgb->G = hsl.L * 255.0;
    rgb->B = hsl.L * 255.0;
  }
  else
  {
    //temporary_1
    double temporary_1;

    if(hsl.L < 0.5)
    {
      temporary_1 = hsl.L * (1.0 + hsl.S);
    }
    else
    {
      temporary_1 = hsl.L + hsl.S - hsl.L * hsl.S;
    }

    //temporary_2
    double temporary_2 = 2.0 * hsl.L - temporary_1;

    //hue
    double hue = hsl.H / 360.0;

    //temporary_R,  temporary_G and temporary_B
    double temporary_R = hue + 0.333;
    double temporary_G = hue;
    double temporary_B = hue - 0.333;

    //ensure temporary_R,  temporary_G and temporary_B are between 0 and 1
    if(temporary_R < 0.0)
      temporary_R += 1.0;
    if(temporary_R > 1.0)
      temporary_R -= 1.0;

    if(temporary_G < 0.0)
      temporary_G += 1.0;
    if(temporary_G > 1.0)
      temporary_G -= 1.0;

    if(temporary_B < 0.0)
      temporary_B += 1.0;
    if(temporary_B > 1.0)
      temporary_B -= 1.0;

    //RED
    if((6.0 * temporary_R) < 1.0)
    {
      rgb->R = round((temporary_2 + (temporary_1 - temporary_2) * 6.0 * temporary_R) * 255.0);
    }
    else if((2.0 * temporary_R) < 1.0)
    {
      rgb->R = round(temporary_1 * 255.0);
    }
    else if((3.0 * temporary_R) < 2.0)
    {
      rgb->R = round((temporary_2 + (temporary_1 - temporary_2) * (0.666 - temporary_R) * 6.0) * 255.0);
    }
    else
    {
      rgb->R = round(temporary_2 * 255.0);
    }

    //GREEN
    if((6.0 * temporary_G) < 1.0)
    {
      rgb->G = round((temporary_2 + (temporary_1 - temporary_2) * 6.0 * temporary_G) * 255.0);
    }
    else if((2.0 * temporary_G) < 1.0)
    {
      rgb->G = round(temporary_1 * 255.0);
    }
    else if((3.0 * temporary_G) < 2.0)
    {
      rgb->G = round((temporary_2 + (temporary_1 - temporary_2) * (0.666 - temporary_G) * 6.0) * 255.0);
    }
    else
    {
      rgb->G = round(temporary_2 * 255.0);
    }

    //BLUE
    if((6.0 * temporary_B) < 1.0)
    {
      rgb->B = round((temporary_2 + (temporary_1 - temporary_2) * 6.0 * temporary_B) * 255.0);
    }
    else if((2.0 * temporary_B) < 1.0)
    {
      rgb->B = round(temporary_1 * 255.0);
    }
    else if((3.0 * temporary_B) < 2.0)
    {
      rgb->B = round((temporary_2 + (temporary_1 - temporary_2) * (0.666 - temporary_B) * 6.0) * 255.0);
    }
    else
    {
      rgb->B = round(temporary_2 * 255.0);
    }
  }
}

void HSL2HEX(HSL hsl, RGB_Hex *rgbh)
{
  RGB rgb;
  HSL2RGB(hsl, &rgb);
  RGB2HEX(rgb, rgbh);
}
