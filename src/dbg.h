#pragma once


#include "ext_deps/ANSI_Utils.h"
#include <stdio.h>



static void Err(const char * flag, const char * str)
{
  printf("[ ");
  RGB_FG_BG(FG, 0, 0, 0, BG, 255, 0, 0);
  printf("Err");
  CresetAll();
  printf(" -> %s ] %s\n", flag, str);
  exit(1);
}

static void Warn(const char * flag, const char * str)
{
  printf("[ ");
  RGB_FG_BG(FG, 0, 0, 0, BG, 255, 212, 0);
  printf("Warn");
  CresetAll();
  printf(" -> %s ] %s\n", flag, str);
}

static void Success(const char * flag, const char * str)
{
  printf("[ ");
  RGB_FG_BG(FG, 0, 0, 0, BG, 58, 196, 0);
  printf("Success");
  CresetAll();
  printf(" -> %s ] %s\n", flag, str);
}

static void Info(const char * flag, const char * str)
{
  printf("[ ");
  RGB_FG_BG(FG, 0, 0, 0, BG, 0, 182, 155);
  printf("Info");
  CresetAll();
  printf(" -> %s ] %s\n", flag, str);
}

#ifdef DEBUG
  void DebugTest()
  {
    Success("Flag Test", "Success");
    Warn("Flag Test", "Warning");
    Err("Flag Test", "Error");
    Info("Flag Test", "Information");
  }
#endif