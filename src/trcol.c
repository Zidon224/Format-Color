#include <stdio.h>

#if defined _WIN32 || _WIN64
  #include <windows.h>
#endif

//MARK: Defined Macros
//Enable this only in dev mode
//#define DEBUG

#include "CLI_Entry.h"



//MARK: Main 
int main(int argc, char * argv[])
{
  #if defined _WIN32 || defined _WIN64
    SetTerminal();
  #endif
  CLIMain(argc, argv);
  return 0;
}
