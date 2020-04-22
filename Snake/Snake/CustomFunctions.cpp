//All custom functions for Game snake implemented here
#include "CustomFunctions.h"
#include <string>
#include <cstring>

//TODO: implement others to handle console appearance
void CustomFunctions::setConsoleSize(int width, int height)
{
	//adjust width and height
	width += 2;
	height += 2;

	std::string strWidth = std::to_string(width);
	std::string strHeight = std::to_string(height);

	//form commandline
	char command[30] = "mode con cols=";
	strcat_s(command, strWidth.c_str());
	strcat_s(command, " lines=");
	strcat_s(command, strHeight.c_str());

	system(command);
}