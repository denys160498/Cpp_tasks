#pragma once
#include "GameMap.h"
#include "Snake.h"

class Game 
{
private:	
	GameMap* MapPtr;
	Snake* SnakePtr;
public:
	Game();
	~Game(); 
	void draw_map() const;
	void clear_map() const;
	void inscribe_snake();
	Snake* get_snake_ptr() const;
};