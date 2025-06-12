#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

HANDLE stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);

string getFilePath(char* buff);

int main()
{
	OPENFILENAMEA f = {sizeof(OPENFILENAMEA)};

	f.lpstrFilter = "text files\0*.txt\0";

	f.lpstrTitle = "TEXT READING FILE";// settitle
	
	char buff[MAX_PATH] = {};
	f.nMaxFile = sizeof(buff);
	f.lpstrFile = buff;

	GetOpenFileNameA(&f);

	// file path
	string filePath = getFilePath(buff);

	HANDLE hFile = CreateFileA(
		filePath.c_str(),
		GENERIC_READ,
		FILE_SHARE_READ,
		NULL,OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		int idmsg_error = MessageBox(0, L"Fail to open", L"Error", MB_OK | MB_ICONERROR);

	}
	else
	{
		char buffer[1024];
		DWORD bytesRead;
		if (ReadFile(hFile, buffer, size(buffer) - 1, &bytesRead, NULL))
		{
			buffer[bytesRead] = '\0'; // Null-terminate
			SetConsoleTextAttribute(stdHandle, 2);
			cout << buffer << endl;
			SetConsoleTextAttribute(stdHandle, 0);
		}
		else
		{
			int idmsg_error = MessageBox(0, L"Fail to Read :", L"Error", MB_OK|MB_ICONERROR);
		}
	}
	
	

	CloseHandle(hFile);
	return 0;
}

string getFilePath(char *buff)
{
	string filePath = "";
	for (int i = 0; buff[i] != '\0'; ++i)
	{
		if (buff[i] == '\\')
		{
			filePath += '\\';
			filePath += '\\';
		}
		else
		{
			filePath += buff[i];
		}
	}
	return filePath;
}
