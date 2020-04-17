//All custom functions for Game snake implemented here
#include "CustomFunctions.h"
#include "windows.h"

//TODO: finish this function and implement others to handle console appearance
void CustomFunctions::setConsoleSize(int width, int height)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD bufferSize = { width, height };
	SetConsoleScreenBufferSize(consoleHandle, bufferSize);
	HWND windowHandle = GetActiveWindow();
	MoveWindow(windowHandle,0,0,width,height,true);
}