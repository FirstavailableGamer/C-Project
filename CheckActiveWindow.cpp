#include <iostream>
#include <Windows.h>

int main()
{

    HWND consoleWindow = GetConsoleWindow();
    HWND activeWindow = GetForegroundWindow();

    if (activeWindow == consoleWindow)
    {
        std::cout << "My Window is active\n";
    }
    else
    {
        std::cout << "My Window is not active\n";
    }

    return 0;
}
