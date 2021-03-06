//This file contains all custom functions for Game "Snake"
#include "CustomFunctions.h"

//TODO: implement other functions to handle console appearance
//TODO: implement custom logger function.
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

char custfuncs::displayMenuItems(std::string items[], int itemsAmount, std::string title)
{
	char choice = '0';

	custfuncs::setConsoleSize(30, itemsAmount);
	system("cls");

	if (title != "")
	{
		std::cout << title << '\n';
	}

	for (int i = 0; i < itemsAmount; i++)
	{
		std::cout << "(" << i + 1 << ") " << items[i] << "\n";
	}
	std::cout << "Make your choice: ";
	choice = _getch();

	return choice;
}

void custfuncs::deleteCurrentWindow()
{
	FreeConsole();
	AttachConsole(ATTACH_PARENT_PROCESS);
}

void custfuncs::logger(logType type, std::string message)
{
	std::string prefix = "";
	const char* pathToLog = "log.txt";
	std::ofstream logFile(pathToLog);

	if (!logFile.is_open())
	{
		std::cout << "Log file is not opened";
		return;
	}
	
	switch (type)
	{
	case log: prefix = "[LOG] - "; break;
	case warning: prefix = "[WARN] - "; break;
	case error: prefix = "[ERROR] - "; break;
	case end: ; break;
	default: std::cout << "Invalid type for logger";
	}

	logFile << prefix << message << '\n';
}