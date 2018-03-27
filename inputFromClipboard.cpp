#define WINVER 0x0500
#include <windows.h>
#include <iostream>
using namespace std;

int main()
{
	cout << "#####" << endl;
	cout << "##  "  << endl;
	cout << "#####" << endl;
	cout << "   ##" << endl;
	cout << "#####" << endl;
	cout << endl;
	Sleep(1000);
	system("cls");

	cout << "## ##" << endl;
	cout << "## ##" << endl;
	cout << "#####" << endl;
	cout << "   ##" << endl;
	cout << "   ##" << endl;
	cout << endl;
	Sleep(1000);
	system("cls");

	cout << "#####" << endl;
	cout << "   ##" << endl;
	cout << "#####" << endl;
	cout << "   ##" << endl;
	cout << "#####" << endl;
	cout << endl;
	Sleep(1000);
	system("cls");

	cout << "#####" << endl;
	cout << "   ##" << endl;
	cout << "#####" << endl;
	cout << "##   " << endl;
	cout << "#####" << endl;
	cout << endl;
	Sleep(1000);
	system("cls");

	cout << "   ##" << endl;
	cout << "   ##" << endl;
	cout << "   ##" << endl;
	cout << "   ##" << endl;
	cout << "   ##" << endl;
	cout << endl;
	Sleep(1000);
	system("cls");
	cout << "Running...";
	
	char ret[1024];
	wchar_t wc;
	INPUT pInput;
	int i; 
	int l;
	setlocale(0, "");
	if( OpenClipboard(NULL) )
		{
		char* data = (char*)GetClipboardData(CF_TEXT);
		if(data)	
		l = strlen(data);

		for (i = 0; i < l; i++)
			{
				MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, &data[i], 1, &wc, 1);
				if (wc != 13) 
				{			
					pInput.type = INPUT_KEYBOARD;
					pInput.ki.wVk = 0;
					pInput.ki.time = 0;
					pInput.ki.wScan = wc;
					pInput.ki.dwFlags = KEYEVENTF_UNICODE;
					SendInput(1, &pInput, sizeof(pInput));
					pInput.ki.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
					SendInput(1, &pInput, sizeof(pInput));
					Sleep(20);
				}
			}
		CloseClipboard();
		}			
	return 0;
}