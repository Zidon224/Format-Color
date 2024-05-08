#pragma once







#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dbg.h"

//#include "core/transColor.h"
#include "core/transColorUtils.h"

#define COLPROC_VER "1.0.0"

char *CLInfo = 
"Help\n"
"Line 2\n"
;

char *GetChRGB2Hex = NULL;
char *GetChRGB2Hsl = NULL;
char *GetChHSL2Rgb = NULL;
char *GetChHSL2Hex = NULL;
char *GetChHEX2Hsl = NULL;
char *GetChHEX2Rgb = NULL;
char *GetFileInput = NULL;

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

static void CLIMain(int ac, char * args[])
{
  //MARK: Check argument count
  if(ac == 1)
  {
    Err("CLI", "No args!");
    Info("CLI", "Run colproc -h or --help to get usage guide.");
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
    else if(strcmp(args[i], "-sc") == 0 || strcmp(args[i], "--show_color") == 0)
    {
      printf("Show Color True...\n");
    }
    else if(strcmp(args[i], "-sca") == 0 || strcmp(args[i], "--show_color_array") == 0)
    {
      printf("Show saved color array...\n");
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
  #ifdef DEBUG
    printf("CLI INPUT TEST: RGB2HEX %s\n", GetChRGB2Hex);
    printf("CLI INPUT TEST: RGB2HSL %s\n", GetChRGB2Hsl);
    printf("CLI INPUT TEST: HSL2RGB %s\n", GetChHSL2Rgb);
    printf("CLI INPUT TEST: HEX2HSL %s\n", GetChHEX2Hsl);
    //printf("CLI INPUT TEST: RGB2HEX R= %d | G= %d | B= %d\n", iR, iG, iB);
  #endif
}
