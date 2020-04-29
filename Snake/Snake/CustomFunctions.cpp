//This file contains all custom functions for Game "Snake"
#include "CustomFunctions.h"

//TODO: implement other functions to handle console appearance
void custfuncs::setConsoleSize(int width, int height)
{
	//adjust width and height
	width += 2;
	height += 2;

	std::string strWidth = std::to_string(width);
	std::string strHeight = std::to_string(height);
	
	//form a commandline
	std::string commandLine = "mode con cols=" + strWidth + " lines=" + strHeight;

	system(commandLine.c_str());
}

void custfuncs::createNewWindow()
{
	FreeConsole();
	AllocConsole();
}

char custfuncs::displayMenuItems(std::string items[], int itemsAmount)
{
	char choice = '0';

	custfuncs::setConsoleSize(30, itemsAmount);
	system("cls");

	for (int i = 0; i < itemsAmount; i++)
	{
		std::cout << "(" << i + 1 << ") " << items[i] << "\n";
	}
	std::cout << "Make your choice: ";
	choice = _getch();

	return choice;
}