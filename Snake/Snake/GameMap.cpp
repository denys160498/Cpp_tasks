#include <iostream>
#include <vector>
#include <string>
#include "GameMap.h"

GameMap::GameMap(char bChar, int w, int h) : borderSign(bChar), width(w + 2), height(h + 2)
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
	for (int i = 0; i <= height; i++)
	{
		for (int j = 0; j <= width; j++)
		{
			std::cout << map[i][j];
		}
		std::cout << std::endl;
	}
}