#include <Windows.h>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <time.h>

extern "C" {
    typedef int (*start_)();
}

int main()
{
    auto hdl = LoadLibraryA("loggerdll.dll");
    if (hdl)
    {
        auto start = (start_)GetProcAddress(hdl, "start");
        if (start!=NULL)
        {
            start();
        }
        else
        {
            printf("Dll Yok");
        }
        FreeLibrary(hdl);
    }
    else
    {
        printf("Dll Yok!!");
    }
}
