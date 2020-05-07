#pragma once
#include <string>
#include <cstring>
#include "windows.h"
#include <iostream>
#include "conio.h"

namespace custfuncs
{
	void setConsoleSize(int, int);
	void createNewWindow();
	char displayMenuItems(std::string [], int , std::string title = "");
}
