/*
Function and definitions for native color selectors
*/


#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ini_writer.h"
#include "CLI_Entry.h"

#if defined _WIN32 || _WIN64
  #include <windows.h>
  #include <Intsafe.h>
  #include <wingdi.h>
#endif

uint8_t Rv;
uint8_t Gv;
uint8_t Bv;
//uint8_t Ro, Go, Bo;

const char * FN_Global;

//My little helper that gets the file name from CLI LMfAO
static void GetFilanameFromCLI(const char * FN)
{
  FN_Global = FN;
}

//Do NOT change!!
static const int DefaultCustomColors[16][3] =
{
  255, 0, 0,
  0, 255, 0,
  0, 0, 255,
  255, 255, 0,
  0, 255, 255,
  255, 0, 255,
  0, 234, 234,
  255, 0, 113,
  200, 0, 0,
  0, 200, 0,
  0, 0, 200,
  200, 200, 0,
  0, 200, 200,
  200, 0, 200,
  115, 115, 115,
  255, 255, 255
};

uint8_t R, G, B;
COLORREF acrCustClr[16];           // array of custom color

static void NativeDlgColorBox(bool DefCol, bool wca)
{
  #if defined _WIN32 || _WIN64
    CHOOSECOLOR cc;                           // common dialog box structure
    
    HBRUSH hbrush;                            // brush handle
    COLORREF rgbCurrent = RGB(255, 128, 128); // initial color selection
    //Load the default color array only when asked from CLI
    if(DefCol)
    {
      for(int i = 0; i < 16; i++)
      {
        R = DefaultCustomColors[i][0];
        G = DefaultCustomColors[i][1];
        B = DefaultCustomColors[i][2];
        acrCustClr[i] = RGB(R, G, B);
      }
    }
    
    // Initialize CHOOSECOLOR 
    ZeroMemory(&cc, sizeof(cc));
    cc.lStructSize = sizeof(cc);
    cc.hwndOwner = NULL;            //No need
    cc.lpCustColors = (LPDWORD) acrCustClr;
    cc.rgbResult = rgbCurrent;
    cc.Flags = CC_FULLOPEN | CC_RGBINIT | CC_SOLIDCOLOR | CC_ANYCOLOR;
 
    if (ChooseColor(&cc))
    {
      hbrush = CreateSolidBrush(cc.rgbResult);
      rgbCurrent = cc.rgbResult;
      //Thank you Ex-ce-pt(github) for help!
      //Get the current RGB color
      Rv = (uint8_t) (GetRValue(rgbCurrent));
      Gv = (uint8_t) (GetGValue(rgbCurrent));
      Bv = (uint8_t) (GetBValue(rgbCurrent));
      uint8_t Ro, Go, Bo;
    
      if(wca)
      {
        char tempR[10];
        char tempG[10];
        char tempB[10];
        char temp[50];
        ini_table_s* OutputColorArray = ini_table_create();

        for(int i = 0; i < 16; i++)
        {
          //Read RGB values from each of the 16 colors
          Ro = (uint8_t) (GetRValue(acrCustClr[i]));
          Go = (uint8_t) (GetGValue(acrCustClr[i]));
          Bo = (uint8_t) (GetBValue(acrCustClr[i]));
  
          itoa(Ro, tempR, 10);
          itoa(Go, tempG, 10);
          itoa(Bo, tempB, 10);
  
          //Define each of the custom color with a nuber from 0 to 16 as a string
          sprintf(temp, "RGBColor_%d", i);
  
          //Assign contents to the file
          ini_table_create_entry(OutputColorArray, temp, "R", tempR);
          ini_table_create_entry(OutputColorArray, temp, "G", tempG);
          ini_table_create_entry(OutputColorArray, temp, "B", tempB);

          #ifdef COLOR_SELECTOR_DEBUG
            printf("Color array: Counter: %d R= %d | G= %d | B= %d\n", i, Ro, Go, Bo);
          #endif
        }
        ini_table_write_to_file(OutputColorArray, FN_Global);
      }
    }
  #endif
  #ifdef __linux__
    FILE *cdb;
    cdb = popen("zenity --color-selection --title 'Pick a Color'", "r");
  #endif
}
