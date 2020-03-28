#pragma once
#include "GameMap.h"
#include "Snake.h"

class Game 
{
private:	
	GameMap* Map;
	Snake* SnakePtr;
public:
	Game();
	~Game();
	void draw_map() const;
	void inscribe_snake();
};