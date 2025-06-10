#include <Windows.h>
#include <iostream>

int main()
{
	HANDLE stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO c = {};
	if (GetConsoleCursorInfo(0, &c)) // oops, Forgot to pass stdHandle Here
	{
		SetConsoleTextAttribute(stdHandle, 2);
		std::cout << "Good Handle" << std::endl;
	}
	else
	{
		int msgid = MessageBox(NULL, L"ERROR", L"ERROR", MB_CANCELTRYCONTINUE | MB_ICONSTOP);
		HANDLE stdHandle2 = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(stdHandle, 4);
		std::cout << "Bad Handle";
	}


	return 0;
}
