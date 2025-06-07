#include <iostream>
#include <Windows.h>

int main()
{
	int id_begirlfriend = 0;
	do
	{
		int id_begirlfriend = MessageBox(0, L"Will you be my Valentine", L"Please", MB_OKCANCEL); if (id_begirlfriend == IDOK)
		{
			int id_begirlfriend = MessageBox(0, L"Nice <3", L":)", MB_OK);
			break;
		}
	} while (id_begirlfriend != IDCANCEL);


	return 0;
}
