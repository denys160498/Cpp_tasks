#pragma once
#include <string>
#include <vector>
#include "Element.h"

class GameMap 
{
private:
	int width;
	int height;
	char borderSign;
	std::vector<std::string> map;
public:
	GameMap(char bChar = '#', int w = 25, int h = 25);
	void draw() const;
	void clear();
	int get_width() const;
	int get_height() const;
	std::vector<std::string>* get_map_ptr();
	void inscribe_element(Element*);
};