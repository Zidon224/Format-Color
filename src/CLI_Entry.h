/*
Contains the main command line function to be called in the main function + other definitions and default settings
*/




#pragma once







#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "dbg.h"


#include "core/transColor.c"
#include "color_dlg_box.h"
#include "clipboard.h"


#define TRCOL_VER "Demo Ver 1"

//And ofc the help string
char *CLInfo = 
"Usage: trcol [conversion options] [convert color types]\n"
"* General Options *\n"
"\n"
"{Short command} | {Long command}  | {Description}\n"
"-h              | --help          | Shows help\n"
"-v              | --version       | Shows the version of the program\n"
"-tinf           | --tehnical_info | Shows the tehnical information abt the program\n"
"-lcs            | --license       | Shows the license + other informations\n"
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
"-ccp            | --color_copy            | Copy the color from the native color selector to clipboard\n"
"-ncs            | --native_color_selector | Triggers display of native color pickers\n"
"-acpk           | --advanced_color_picker | Triggers the builtin color picker (Has custom user interface)\n"
"-mcc:           | --multi_color_convert:  | Converts multiple colors from a format to another at once [Requires an input file path in between \" \" or ' ']\n"
"\n"
;

char *Defaults = 
{
  "- - - - Default Options - - - -\n"
  "{Short command} | {Long command}      | {value}\n"
  "-pcd             --post_convert_debug | true\n"
  "\n"
  "\n"
}
;

char *Thehnical_info = 
{
  "- - - - Tegnical information - - - -\n"
  "built with: GCC 10.3.0\n"
  "crossplatform: yes (Linux , Windows)\n"
  "Programing language used: C\n"
  "License: (to be choosen soon...)\n"
  "Internal / External library(s): transformColor\n"
  "Author(s): Zidon224\n"
  "Source code: https://github.com/Zidon224/Transform-Color\n"
}
;

//This may be kind of fucked LMFAO
char *GetChRGB2Hex = NULL;
char *GetChRGB2Hsl = NULL;
char *GetChHSL2Rgb = NULL;
char *GetChHSL2Hex = NULL;
char *GetChHEX2Hsl = NULL;
char *GetChHEX2Rgb = NULL;
char *GetFileInput = NULL;
char *Temporarry = NULL;

bool postConvDebug = false;
bool HideMessages = false;
bool ShowColor = true;
bool conversionState = false;
bool ncsClipboard = false;
bool cmd_check;
//and this 1 too :)))
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
  //It only accepts integer RGB input and some aditional preconversions are required to get rgb integer values (24bit true color Terminal)
  //Look https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797 here too get more info about ansi escapes
  RGB_FG(FG, R, G, B);
  printf("████████████\n");
  CresetAll();
}

static void CLIMain(int ac, char * args[])
{
  //MARK: Check args count
  if(ac == 1)
  {
    Err("CLI", "No args!");
    Info("CLI", "Run trcol -h or --help to get usage guide.");
  }

  //Process each command line argument
  for(int i = 1; i < ac; i++)
  {
    //MARK: Show Info on CMD
    if(strcmp(args[i], "-h") == 0 || strcmp(args[i], "--help") == 0)
    {
      cmd_check = true;
      printf("%s", CLInfo);
    }
    else if(strcmp(args[i], "-v") == 0 || strcmp(args[i], "--version") == 0)
    {
      cmd_check = true;
      printf("Version: %s\n", TRCOL_VER);
    }
    else if(strcmp(args[i], "-tinf") == 0 || strcmp(args[i], "--tehnical_info") == 0)
    {
      cmd_check = true;
      printf("%s", Thehnical_info);
    }
    else if(strcmp(args[i], "-sdo") == 0 || strcmp(args[i], "--show_default_options") == 0)
    {
      cmd_check = true;
      printf("%s \n", Defaults);
    }
    //idk if should I completely cancel this XD
    //MARK: CLI debug test
    else if(strcmp(args[i], "-dbg_test") == 0)
    {
      #ifdef DEBUG
        DebugTest();
      #else
        Err("CLI input", "Option not available!");
      #endif
    }
    //Not yet
    else if(strcmp(args[i], "-lcs") == 0 || strcmp(args[i], "--license") == 0)
    {
      cmd_check = true;
      printf("License: ... \n");
    }
    else if(strcmp(args[i], "-ccp") == 0 || strcmp(args[i], "--color_copy") == 0)
    {
      cmd_check = true;
      ncsClipboard = true; //Enables the copy to clipboard of the selected color from the native color selector dialog
      //printf("Color copied to clipboard.\n"); //is this really necessary tho?
    }
    //This option will trigger open the native color picker on linux and windows too
    else if(strcmp(args[i], "-ncs") == 0 || strcmp(args[i], "--native_color_selector") == 0)
    {
      cmd_check = true;
      #ifdef DEBUG
        printf("Open Color Dialog Box\n");
      #endif
      NativeDlgColorBox();
      char tmp[20];
      sprintf(tmp, "%d %d %d", Rv, Gv, Bv);
      printf("%s", tmp);
      if(ncsClipboard)
      {
        Clipboard_copy(tmp);
      }
    }
    //This will trigger the builtin color picker which can also scan colors from screen pixels too (like Microsoft's color picker from Windows power toys)
    //Todo...
    else if(strcmp(args[i], "-acpk") == 0 || strcmp(args[i], "--advanced_color_picker") == 0)
    {
      cmd_check = true;
      printf("Advanced color picker...\n To be inmplemented...\n");
    }
    //This prevents the colored bar from being displayed after conversion
    //Idk why someone would like to disable this feature but I decided to add it tho. LoL
    else if(strcmp(args[i], "-dsc") == 0 || strcmp(args[i], "--disable_show_color") == 0)
    {
      cmd_check = true;
      ShowColor = false;
    }
    //Not sure what can I do with this
    //Any other ideeas are good too
    else if(strcmp(args[i], "-sca") == 0 || strcmp(args[i], "--show_color_array") == 0)
    {
      cmd_check = true;
      printf("Show saved color array...\n");
    }
    //This hides the post debug message so you don't get annoyed all the time with "[ Success -> Conversion ] Color converted successfully!"
    else if(strcmp(args[i], "-pcd") == 0 || strcmp(args[i], "--post_convert_debug") == 0)
    {
      cmd_check = true;
      postConvDebug = true;
    }
    //And from here we have the actuall conversion commands
    //MARK: Converts commands
    else if(strcmp(args[i], "-rgb2hex:") == 0)
    {
      //Check if the secondary argument was provided to the parameter
      if(i + 1 < ac)
      {
        conversionState = true;
        GetChRGB2Hex = args[i + 1];
        i++; //Move to the next argument
        //Scan for the assigned input from the second argument of the parameter
        sscanf(GetChRGB2Hex, "%hhd%hhd%hhd", &inRgb.R, &inRgb.G, &inRgb.B);
        //And convert the color
        RGB2HEX(inRgb, &outRgbh);
        //Then print it to the stdout
        printRGBH(outRgbh);
        //Print characters as blocks with true RGB (24 bits) color only if this option is enabled
        //Function defined at line 97
        if(ShowColor)
        {
          printColor(inRgb.R, inRgb.G, inRgb.B);
        }
      }
      //And finally check if color input was assigned
      else
      {
        Err("RGB to HEX", "No RGB input was given!");
      }
      //Set this to 1 so it dosen't give error for unkown arguments that are actually existing.
      cmd_check = true;
      //And so one....
    }
    else if(strcmp(args[i], "-rgb2hsl:") == 0)
    {
      if(i + 1 < ac)
      {
        conversionState = true;
        GetChRGB2Hsl = args[i + 1];
        i++;
        sscanf(GetChRGB2Hsl, "%hhd %hhd %hhd", &inRgbHsl.R, &inRgbHsl.G, &inRgbHsl.B);
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
      cmd_check = true;
    }
    else if(strcmp(args[i], "-hsl2rgb:") == 0)
    {
      if(i + 1 < ac)
      {
        conversionState = true;
        GetChHSL2Rgb = args[i + 1];
        i++;
        sscanf(GetChHSL2Rgb, "%d %lf %lf", &inHSL.H, &inHSL.S, &inHSL.L);
        HSL2RGB(inHSL, &outRgbHsl);
        printRGB(outRgbHsl);
        if(ShowColor)
        {
          printColor(outRgbHsl.R, outRgbHsl.G, outRgbHsl.B);
        }
      }
      else
      {
        Err("HSL to RGB", "No HSL input was given!");
      }
      cmd_check = true;
    }
    else if(strcmp(args[i], "-hsl2hex:") == 0)
    {
      if(i + 1 < ac)
      {
        conversionState = true;
        GetChHSL2Hex = args[i + 1];
        i++;
        sscanf(GetChHSL2Hex, "%d %lf %lf", &inHSLHex.H, &inHSLHex.S, &inHSLHex.L);
        HSL2HEX(inHSLHex, &outHslHex);
        printRGBH(outHslHex);
        if(ShowColor)
        {
          //Some extra color conversion is required since terminals support only true color RGB
          HEX2RGB(outHslHex, &outRgbHex);
          printColor(outRgbHex.R, outRgbHex.G, outRgbHex.B);
        }
      }
      else
      {
        Err("HSL to HEX", "No HSL input was given!");
      }
      cmd_check = true;
    }
    else if(strcmp(args[i], "-hex2hsl:") == 0)
    {
      if(i + 1 < ac)
      {
        conversionState = true;
        GetChHEX2Hsl = args[i + 1];
        i++;
        sscanf(GetChHEX2Hsl, "%s %s %s", inHexHsl.R, inHexHsl.G, inHexHsl.B);
        HEX2HSL(inHexHsl, &outHexHsl);
        printHSL(outHexHsl);
        if(ShowColor)
        {
          //Same for this 1
          HEX2RGB(inHexHsl, &outRgbHex);
          printColor(outRgbHex.R, outRgbHex.G, outRgbHex.B);
        }
      }
      else
      {
        Err("HEX to HSL", "No HEX input was given!");
      }
      cmd_check = true;
    }
    else if(strcmp(args[i], "-hex2rgb:") == 0)
    {
      if(i + 1 < ac)
      {
        conversionState = true;
        GetChHEX2Rgb = args[i + 1];
        i++;
        sscanf(GetChHEX2Rgb, "%s %s %s", inRgbHex.R, inRgbHex.G, inRgbHex.B);
        HEX2RGB(inRgbHex, &outRgbHex);
        printRGB(outRgbHex);
        if(ShowColor)
        {
          printColor(outRgbHex.R, outRgbHex.G, outRgbHex.B);
        }
      }
      else
      {
        Err("Hex to RGB", "No HEX input was given!");
      }
      cmd_check = true;
    }
    //From here there are commands for checking if a color of any format is correctly assigned
    //MARK: Color validations
    else if(strcmp(args[i], "-is_rgb:") == 0)
    {
      if(i + 1 < ac)
      {
        GetChRGB2Hex = args[i + 1];
        i++;
        sscanf(GetChRGB2Hex, "%hhd %hhd %hhd", &inRgbHsl.R, &inRgbHsl.G, &inRgbHsl.B);
        if(!checkRGB(inRgbHsl))
        {
          printf("RGB is valid\n");
        }
        else
        {
          Err("RGB Validation", "RGB input is invalid!\n");
        }
      }
      cmd_check = true;
    }
    else if(strcmp(args[i], "-is_hex:") == 0)
    {
      if(i + 1 < ac)
      {
        //inHexHsl
        GetChHEX2Hsl = args[i + 1];
        sscanf(GetChHEX2Hsl, "%s %s %s", inHexHsl.R, inHexHsl.G, inHexHsl.B);
        if(checkRGB_HEX(inHexHsl))
        {
          printf("Hex is valid\n");
        }
        else
        {
          Err("Hex validation", "Hex is invalid!\n");
        }
      }
      cmd_check = true;
    }
    else if(strcmp(args[i], "-is_hsl:") == 0)
    {
      if(i + 1 < ac)
      {
        //inHexHsl
        GetChHSL2Rgb = args[i + 1];
        sscanf(GetChHSL2Rgb, "%d %lf %lf", &inHSL.H, &inHSL.S, &inHSL.L);
        if(checkHSL(inHSL))
        {
          printf("HSL is valid\n");
        }
        else
        {
          Err("HSL validation", "HSL is invalid!\n");
        }
      }
      cmd_check = true;
    }
    //With this command the user can convert multiple colors at the same time from a format to another using json structure
    //Todo...
    //MARK: Misc commands
    else if(strcmp(args[i], "-mcc:") == 0 || strcmp(args[i], "--multi_color_convert:") == 0)
    {
      if(i + 1 < ac)
      {
        GetFileInput = args[i + 1];
        i++;
        printf("To be implemented...\n");
      }
      else
      {
        Err("Multi color convert", "Missing filename!");
      }
      cmd_check = true;
    }
    //Only for testing purposes!!
    else if(strcmp(args[i], "-cpb:") == 0)
    {
      if(i + 1 < ac)
      {
        Temporarry = args[i + 1];
        i++;
        Clipboard_copy(Temporarry);
      }
      cmd_check = true;
    }
    //And finally check for any unknown args entered and exit
    //The wrong way to do that LOL
    /*else
    {
      char temp[100];
      sprintf(temp, "Unknown argument %s", args[i]);
      Err("CLI", temp);
    }*/
    //And the right way
    if(!cmd_check)
    {
      char temp[100];
      sprintf(temp, "Unknown argument %s", args[i]);
      Err("CLI", temp);
    }
  }

  //Show this message only after conversion and make sure to not show it when is not necessary
  if(postConvDebug && conversionState)
  {
    Success("Conversion", "Color converted successfully!");
  }
  //Again for testing purposes only
  #ifdef DEBUG_CLI_ENTRY
    printf("CLI INPUT TEST: RGB2HEX %s\n", GetChRGB2Hex);
    printf("CLI INPUT TEST: RGB2HSL %s\n", GetChRGB2Hsl);
    printf("CLI INPUT TEST: HSL2RGB %s\n", GetChHSL2Rgb);
    printf("CLI INPUT TEST: HEX2HSL %s\n", GetChHEX2Hsl);
    printf("CLI INPUT TEST: RGB2HEX2 %d | %d | %d \n", inRgb.R, inRgb.G, inRgb.B);
    printf("CLI INPUT TEST: HSL2RGB2 %d | %f | %f\n", inHSL.H, inHSL.S, inHSL.L);
    printf("Test H= %d | S= %4.2lf | L= %4.2lf", inHSL.H, inHSL.S, inHSL.L);
    //printf("CLI INPUT TEST: RGB2HEX R= %d | G= %d | B= %d\n", iR, iG, iB);
  #endif
}
