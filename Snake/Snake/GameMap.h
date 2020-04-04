#pragma once
#include <string>
#include <vector>

class GameMap 
{
private:
	int width;
	int height;
	char borderSign;
public:
	std::vector<std::string> map;
	
	GameMap(char bChar = '#' , int w = 25, int h = 25);
	void draw() const;
	void clear();
	int get_width() const;
	int get_height() const;
	std::vector<std::string>* get_map_ptr();
};