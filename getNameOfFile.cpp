#include <Windows.h>
#include <iostream>

using namespace std;

int main()
{
	OPENFILENAMEA f = {sizeof(OPENFILENAMEA)};

	f.lpstrFilter = "png files\0*.png\0jpg files\0*.jpg\0";

	f.lpstrTitle = "Dialog box lmao";// settitle
	
	char buff[MAX_PATH] = {};
	f.nMaxFile = sizeof(buff);
	f.lpstrFile = buff;

	GetOpenFileNameA(&f);

	for (char c : buff)
	{
		std::cout << c;
	}

	return 0;
}
