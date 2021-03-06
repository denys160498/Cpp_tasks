#include <iostream>
#include <vector>
#include <string>
#include "GameMap.h"

GameMap::GameMap(char bChar, int w, int h) : borderSign(bChar), width(w), height(h)
{
	for (int i = 0; i <= height; i++)
	{
		map.push_back("");
		for (int j = 0; j <= width; j++)
		{
			if (i == 0 || i == height || j == 0 || j == width)
			{
				map[i].push_back(bChar);
				continue;
			}
			map[i].push_back(' ');
		}
	}
}

void GameMap::draw() const
{
	system("cls");
	for (int i = 0; i <= height; i++)
	{
		for (int j = 0; j <= width; j++)
		{
			std::cout << map[i][j];
			std::cout << ' '; //to adjust map`s appearance
		}
		std::cout << std::endl;
	}
}

int GameMap::get_width() const
{
	return this->width;
}

int GameMap::get_height() const
{
	return this->height;
}

std::vector<std::string>* GameMap::get_map_ptr()
{
	return &map;
}

void GameMap::clear() 
{
	for (int i = 0; i <= height; i++)
	{
		for (int j = 0; j <= width; j++)
		{
			if (i == 0 || i == height || j == 0 || j == width)
			{
				continue;
			}
			map[i][j] = ' ';
		}
	}
}

void GameMap::inscribe_element(Element* element)
{
	map[element->get_posY()][element->get_posX()] = element->get_appearance();
}