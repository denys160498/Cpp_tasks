#pragma once
#include <string>
#include <vector>

class GameMap 
{
private:
	int width;
	int height;
	char borderSign;
	std::vector<std::string> map;
public:
	GameMap(char bChar = '#' , int w = 25, int h = 25);

	void draw() const;
	void refresh();

};