#include <stdio.h>

#if defined _WIN32 || defined _WIN64
  #include <windows.h>
#endif



static void Clipboard_copy(char *str)
{
    const size_t strl = strlen(str) + 1;
    HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, strl);
    memcpy(GlobalLock(hMem), str, strl);
	GlobalUnlock(hMem);
	OpenClipboard(0);
    #ifdef CLIPBOARD_DEBUG
      printf("Clipboard opened\n");
    #endif
	EmptyClipboard();
    #ifdef CLIPBOARD_DEBUG
      printf("Clipboard reset\n")
    #endif
	SetClipboardData(CF_TEXT, hMem);
    #ifdef CLIPBOARD_DEBUG
      printf("Clipboard string set to: %s\n", str);
    #endif
	CloseClipboard();
    #ifdef CLIPBOARD_DEBUG
      printf("Clipboard closed");
    #endif
}