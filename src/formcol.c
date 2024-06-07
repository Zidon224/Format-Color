#include <stdio.h>

#if defined _WIN32 || _WIN64
  #include <windows.h>
#endif

//MARK: Defined Macros
//Enable those macros only in dev mode
//#define DEBUG_CLI_ENTRY
//#define CLIPBOARD_DEBUG

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
