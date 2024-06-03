#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "ext_deps/tconfig/config.c"
#include "color_dlg_box.h"

#if defined _WIN32 || defined _WIN64
  #include <windows.h>
  #include <wingdi.h>
#endif



//ini_table_s* config = ini_table_create();


static void Write_Settings()
{
  //Todo
}

static void Write_Color_Array(const char* filename, int colorCount, COLORREF colors[])
{
  uint8_t Ro, Go, Bo;
  ini_table_s* OutputColorArray = ini_table_create();
  
  //Used to create section iteration depending on colorCount
  char temp[20];

  //Variables used to store the converted int to char and then passed to the ini structure
  char tempR[10];
  char tempG[10];
  char tempB[10];
  for(int i = 0; i < colorCount; i++)
  {
    
    #ifdef COLOR_ARRAY_WRITER
      printf("Color array: Counter: %d R= %d | G= %d | B= %d\n", i, Ro, Go, Bo);
    #endif

    //Read RGB values from each of the 16 colors
    Ro = (uint8_t) (GetRValue(colors[i]));
    Go = (uint8_t) (GetGValue(colors[i]));
    Bo = (uint8_t) (GetBValue(colors[i]));
    sprintf(temp, "Color%d", i);
    //Convert RGB int to RGB char
    itoa(Ro, tempR, 10);
    itoa(Go, tempG, 10);
    itoa(Bo, tempB, 10);

    //Assign contents to the file
    ini_table_create_entry(OutputColorArray, temp, "R", tempR);
    ini_table_create_entry(OutputColorArray, temp, "G", tempG);
    ini_table_create_entry(OutputColorArray, temp, "B", tempB);
  }
  ini_table_write_to_file(OutputColorArray, filename);
}