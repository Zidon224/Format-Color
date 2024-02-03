//Basic functions for handling debug printing using my ansi escape codes library



#pragma once




#include "ext_deps/ANSI_utils.h"
#include <stdio.h>


static void Info(const char *infoStr)
{
    XtermFG(FG, 27);
    printf("[Info] ");
    CresetAll();
    puts(infoStr);
}

static void Success(const char *sccStr)
{
    XtermFG(FG, 46);
    printf("[Success] ");
    CresetAll();
    puts(sccStr);
}

static void Warn(const char*warStr)
{
    XtermFG(FG, 214);
    printf("[Warn] ");
    CresetAll();
    puts(warStr);
}

static void Err(const char *errStr)
{
    XtermFG(FG, 196);
    printf("[Err] ");
    CresetAll();
    puts(errStr);
}
