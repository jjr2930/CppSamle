#include <iostream>
#include <Windows.h>

#include "Console.h"
#include "Const.h"

/*
* 싱글톤 멤버들 초기화와 정의
*/

SINGLETON_IMPLIMETATION(Console) 
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top;

	//끝자리에 문자열 마감문자 \0을 넣어주기 위해 스크린 크기 보다 1개 더 키운다.
	auto pixelSize = sizeof(char) * consoleHeight * consoleWidth + 1;
	pixels = (char*)malloc(pixelSize);
	memset(pixels, 0, pixelSize);
}

void Console::Clear()
{
	memset(pixels, ' ', sizeof(char) * consoleHeight * consoleWidth);
}

void Console::SetPixel(const int& x, const int& y, const std::string value)
{
	size_t valueSize = value.size();
	int startIndex = y * consoleWidth + x; 
	for (size_t i = 0; i < valueSize; i++)
	{
		int index = startIndex + i;
		pixels[index] = value[i];
	}
}

void Console::DrawConsole()
{
	COORD pos = {0, 0};
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);

	std::cout << pixels;
}
