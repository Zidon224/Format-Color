
#include "../format_color.h"


void printRGB(RGB rgb)
{
  printf("%d %d %d\n", rgb.R, rgb.G, rgb.B);
}

void printRGBH(RGB_Hex rgbh)
{
  printf("#%s%s%s\n", rgbh.R, rgbh.G, rgbh.B);
}

void printHSL(HSL hsl)
{
  printf("%d %4.2lf %4.2lf\n", hsl.H, hsl.S, hsl.L);
}