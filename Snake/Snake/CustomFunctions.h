#pragma once
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include "windows.h"
#include "conio.h"

namespace custfuncs
{
	enum logType
	{
		log,
		warning,
		error,
		end
	};

	void setConsoleSize(int, int);
	void createNewWindow();
	void deleteCurrentWindow();
	char displayMenuItems(std::string [], int , std::string title = "");
	void logger(logType ,std::string );
}
