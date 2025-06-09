#include <iostream>
#include <Windows.h>
#include <ctype.h>

using namespace std;

BOOL IsTypingUppercase();

int main()
{

    string text = "";
    bool keyPressed[256] = { false };
    while (true)
    {
        for (int i = 0; i < 255; i++)
        {

            bool isCurrentlyPressed = (GetAsyncKeyState(i) & 0x8000) != 0;

            // Only process if key was just pressed (not held)
            if (isCurrentlyPressed && !keyPressed[i])
            {
                keyPressed[i] = true; // Mark as pressed

                if (i >= 'A' && i <= 'Z')
                {
                    if (IsTypingUppercase())
                    {
                        text += (char)i; // Already uppercase
                    }
                    else
                    {
                        text += (char)tolower(i); // Convert to lowercase
                    }
                }
                else
                {
                    switch (i)
                    {
                    case VK_RETURN:
                        text += '\n';
                        break;
                    case VK_BACK:
                        if (text.length() != 0)
                        {
                            text.pop_back();
                        }
                        break;
                    case VK_SPACE:
                        text += ' ';
                        break;
                    default:
                        break;
                    }
                }
                system("cls");
                cout << text;
            }
            else if (!isCurrentlyPressed)
            {
                keyPressed[i] = false; // Key was released
            }
        }
        Sleep(50);
    }

    cin.get();

    return 0;
}

BOOL IsTypingUppercase()
{
    BOOL capsLockOn = (GetKeyState(VK_CAPITAL) & 0x0001) != 0;
    BOOL shiftPressed = (GetKeyState(VK_SHIFT) & 0x8000) != 0;

    // Uppercase if: (CAPS LOCK on AND Shift not pressed) OR
    //               (CAPS LOCK off AND Shift pressed)
    return capsLockOn ^ shiftPressed; // XOR operation
}
