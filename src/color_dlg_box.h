/*
Function and definitions for native color selectors
*/


#pragma once

#include <stdio.h>
#include <stdlib.h>

#if defined _WIN32 || _WIN64
  #include <windows.h>
  #include <Intsafe.h>
  #include <wingdi.h>
#endif

uint8_t Rv;
uint8_t Gv;
uint8_t Bv;

static void NativeDlgColorBox()
{
  #if defined _WIN32 || _WIN64
    CHOOSECOLOR cc;                 // common dialog box structure
    static COLORREF acrCustClr[16]; // array of custom colors
    HBRUSH hbrush;                  // brush handle
    COLORREF rgbCurrent;            // initial color selection
    

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
      Rv = (uint8_t) (GetRValue(rgbCurrent));
      Gv = (uint8_t) (GetGValue(rgbCurrent));
      Bv = (uint8_t) (GetBValue(rgbCurrent));
      #ifdef COLOR_SELECTOR_DEBUG
        printf("[Debug] - R: %d | G: %d | B: %d\n", Rv, Gv, Bv);
      #endif
    }
  #endif
  #ifdef __linux__
    FILE *cdb;
    cdb = popen("zenity --color-selection --title 'Pick a Color'", "r");
  #endif
}
