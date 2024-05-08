/*
Contains the main command line function to be called in the main function + other definitions and default settings
*/




#pragma once







#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "dbg.h"

//#include "core/transColor.h"
#include "core/transColor.c"

#define COLPROC_VER "1.0.0"

char *CLInfo = 
"Usage: trcol [conversion options] [convert color types]\n"
"* General Options *\n"
"\n"
"{Short command} | {Long command} | {Description}\n"
"-h              | --help         | Shows help\n"
"-v              | --version      | Shows the version of the program\n"
"-lcs            | --license      | Shows the license + other informations\n"
"\n"
"\n"
"* Conversion commands *\n"
"Important! Command parameters must be separated by a sinlge space in between \" \" or ' '\n"
"\n"
"{Command} | {Parameters & types of prarameters} | {Description}\n"
"-rgb2hex: <int:R> <int:G> <int:B>               | Converts a color from RGB input to hexadecimal color type\n"
"-rgb2hsl: <int:R> <int:G> <int:B>               | Converts a color from RGB input to Hue, Saturation, Lightness color type\n"
"-hsl2rgb: <int:H> <float:S> <floatL:>           | Converts a color from Hue, Saturation, Lightness to RGB color type\n"
"-hsl2hex: <int:H> <float:S> <floatL:>           | Converts a color from Hue, Saturation, Lightness to hexadecimal color type\n"
"-hex2hsl: <char:R> <char:G> <char:B>            | Converts a color from hexadecimal color input to Hue, Saturation, Lightness\n"
"-hex2rgb: <char:R> <char:G> <char:B>            | Converts a color from hexadecimal color input to RGB color type \n"
"\n"
"# convert color options #\n"
"Important! color converting options must be placed before using the color conversion types\n"
"\n"
"{Short command} | {Long command}            | {Description}\n"
"-dsc            | --disable_show_color      | No true color is shown\n"
"-hpcd           | --hide_post_convert_debug | No debug information will be displayed on after conversion\n"
"\n"
"\n"
"* Extra Features *\n"
"\n"
"{Short command} | {Long command}          | {Description}\n"
"-ncpk           | --native_color_picker   | Triggers display of native color pickers\n"
"-acpk           | --advanced_color_picker | Triggers the builtin color picker (Has custom user interface)\n"
"-mcc:           | --multi_color_convert:  | Converts multiple colors from a format to another at once [Requires an input file path in between \" \" or ' ']\n"
"\n"
;

char *GetChRGB2Hex = NULL;
char *GetChRGB2Hsl = NULL;
char *GetChHSL2Rgb = NULL;
char *GetChHSL2Hex = NULL;
char *GetChHEX2Hsl = NULL;
char *GetChHEX2Rgb = NULL;
char *GetFileInput = NULL;

bool postConvDebug = true;
bool ShowColor = true;

RGB inRgb;
RGB inRgbHsl;
RGB outRgbHsl;
RGB_Hex outRgbh;
HSL outHSL;
HSL inHSL;
HSL inHSLHex;
RGB_Hex outHslHex;
RGB_Hex inHexHsl;
HSL outHexHsl;
RGB_Hex inRgbHex;
RGB outRgbHex;

//The magic feature of the program
static void printColor(int R, int G, int B)
{
  printf("Output color: ");
  RGB_FG(FG, R, G, B);
  printf("████████████\n");
  CresetAll();
}

static void CLIMain(int ac, char * args[])
{
  //MARK: Check argument count
  if(ac == 1)
  {
    Err("CLI", "No args!");
    Info("CLI", "Run trcol -h or --help to get usage guide.");
  }

  for(int i = 1; i < ac; i++)
  {
    //MARK: Show Info on CMD
    if(strcmp(args[i], "-h") == 0 || strcmp(args[i], "--help") == 0)
    {
      printf("%s", CLInfo);
    }
    else if(strcmp(args[i], "-v") == 0 || strcmp(args[i], "--version") == 0)
    {
      printf("Version %s\n", COLPROC_VER);
    }
    else if(strcmp(args[i], "-dbg_test") == 0)
    {
      #ifdef DEBUG
        DebugTest();
      #else
        Err("CLI input", "Option not available!");
      #endif
    }
    else if(strcmp(args[i], "-lcs") == 0 || strcmp(args[i], "--license") == 0)
    {
      printf("License: ... \n");
    }
    else if(strcmp(args[i], "-ncpk") == 0 || strcmp(args[i], "--native_color_picker") == 0)
    {
      printf("Native color picker...\n");
    }
    else if(strcmp(args[i], "-acpk") == 0 || strcmp(args[i], "--advanced_color_picker") == 0)
    {
      printf("Advanced color picker...\n");
    }
    else if(strcmp(args[i], "-dsc") == 0 || strcmp(args[i], "--disable_show_color") == 0)
    {
      ShowColor = false;
    }
    else if(strcmp(args[i], "-sca") == 0 || strcmp(args[i], "--show_color_array") == 0)
    {
      printf("Show saved color array...\n");
    }
    else if(strcmp(args[i], "-hpcd") == 0 || strcmp(args[i], "--hide_post_convert_debug") == 0)
    {
      postConvDebug = false;
    }
    else if(strcmp(args[i], "-rgb2hex:") == 0)
    {
      if(i + 1 < ac)
      {
        GetChRGB2Hex = args[i + 1];
        i++;
        sscanf(GetChRGB2Hex, "%d%d%d", &inRgb.R, &inRgb.G, &inRgb.B);
        RGB2HEX(inRgb, &outRgbh);
        printRGBH(outRgbh);
        if(ShowColor)
        {
          printColor(inRgb.R, inRgb.G, inRgb.B);
        }
      }
      else
      {
        Err("RGB to HEX", "No RGB input was given!");
      }
    }
    else if(strcmp(args[i], "-rgb2hsl:") == 0)
    {
      if(i + 1 < ac)
      {
        GetChRGB2Hsl = args[i + 1];
        i++;
        sscanf(GetChRGB2Hsl, "%d%d%d", &inRgbHsl.R, &inRgbHsl.G, &inRgbHsl.B);
        RGB2HSL(inRgbHsl, &outHSL);
        printHSL(outHSL);
        if(ShowColor)
        {
          printColor(inRgbHsl.R, inRgbHsl.G, inRgbHsl.B);
        }
      }
      else
      {
        Err("RGB to HSL", "No RGB input was given!");
      }
    }
    else if(strcmp(args[i], "-hsl2rgb:") == 0)
    {
      if(i + 1 < ac)
      {
        GetChHSL2Rgb = args[i + 1];
        i++;
        sscanf(GetChHSL2Rgb, "%d %4.2lf %4.2lf", &inHSL.H, &inHSL.S, &inHSL.L);
        //MARK: HSL2RGB FAILED!!!
        HSL2RGB(inHSL, &outRgbHsl);
        printRGB(outRgbHsl);
      }
      else
      {
        Err("HSL to RGB", "No HSL input was given!");
      }
    }
    else if(strcmp(args[i], "-hsl2hex:") == 0)
    {
      if(i + 1 < ac)
      {
        GetChHSL2Hex = args[i + 1];
        i++;
        sscanf(GetChHSL2Hex, "%d %4.2lf %4.2lf", &inHSLHex.H, &inHSLHex.S, &inHSLHex.S);
        //MARK: HSL2HEX FAILED!!!
        HSL2HEX(inHSLHex, &outHslHex);
        printRGBH(outHslHex);
      }
      else
      {
        Err("HSL to HEX", "No HSL input was given!");
      }
    }
    else if(strcmp(args[i], "-hex2hsl:") == 0)
    {
      if(i + 1 < ac)
      {
        GetChHEX2Hsl = args[i + 1];
        i++;
        sscanf(GetChHEX2Hsl, "%s%s%s", &inHexHsl.R, &inHexHsl.G, &inHexHsl.B);
        HEX2HSL(inHexHsl, &outHexHsl);
        printHSL(outHexHsl);
      }
      else
      {
        Err("HEX to HSL", "No HEX input was given!");
      }
    }
    else if(strcmp(args[i], "-hex2rgb:") == 0)
    {
      if(i + 1 < ac)
      {
        GetChHEX2Rgb = args[i + 1];
        i++;
        sscanf(GetChHEX2Rgb, "%s%s%s", &inRgbHex.R, &inRgbHex.G, &inRgbHex.B);
        HEX2RGB(inRgbHex, &outRgbHex);
        printRGB(outRgbHex);
      }
      else
      {
        Err("Hex to RGB", "No HEX input was given!");
      }
    }
    else if(strcmp(args[i], "-mcc:") == 0 || strcmp(args[i], "--multi_color_convert:"))
    {
      if(i + 1 < ac)
      {
        GetFileInput = args[i + 1];
        i++;
      }
      else
      {
        Err("Multi color convert", "Missing filename!");
      }
    }
    else
    {
      char temp[100];
      sprintf(temp, "Unknown argument %s", args[i]);
      Err("CLI", temp);
    }
  }

  if(postConvDebug)
  {
    Success("Conversion", "Color converted successfully!");
  }
  #ifdef DEBUG
    printf("CLI INPUT TEST: RGB2HEX %s\n", GetChRGB2Hex);
    printf("CLI INPUT TEST: RGB2HSL %s\n", GetChRGB2Hsl);
    printf("CLI INPUT TEST: HSL2RGB %s\n", GetChHSL2Rgb);
    printf("CLI INPUT TEST: HEX2HSL %s\n", GetChHEX2Hsl);
    //printf("CLI INPUT TEST: RGB2HEX R= %d | G= %d | B= %d\n", iR, iG, iB);
  #endif
}
