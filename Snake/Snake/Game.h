#pragma once
#include "GameMap.h"
#include "Snake.h"

class Game 
{
private:	
	GameMap* Map;
	Snake* SnakeObj;
public:
	Game();
	~Game();
	void draw_map() const;
};