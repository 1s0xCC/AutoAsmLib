// Test.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include "../AutoAsmLib/asm.h"

#pragma comment(lib, "../Release/AutoAsmLib.lib")


int test() {
	char* mem = new char[1024];

	return 1;
}


int main()
{
	HWND hWnd = FindWindow(NULL,L"网易有道词典");


	char buffer[1024] = { NULL };
	ZeroMemory(buffer, 1024);
	sprintf_s(buffer,
		"globalalloc(new,1024)\n"
		"new:\n"
		"dd #%d\n"
		,987654);

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS,FALSE,17872);
	std::string script;
	script += "globalalloc(new,1024)\n";
	script += "new:\n";
	script += "dd #"+std::to_string(123456)+"\n";

	if (AutoAssemble(hProcess, buffer)) {
		printf("%x\n", GetAddress(hProcess,"new"));
	}
	else {
		printf("false\n");
	}
	printf("%s\n",Ver());
	system("pause");
    return 0;
}

