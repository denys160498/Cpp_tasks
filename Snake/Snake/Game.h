#pragma once
#include "GameMap.h"
#include "Snake.h"
#include "Element.h"

class Game 
{
private:	
	GameMap* MapPtr;
	Snake* SnakePtr;
public:
	Game(GameMap*, Snake*);
	void inscribe_snake_on_map();
	Snake* get_snake_ptr() const;
	Element* create_random_element();
	bool check_is_snake_on_element(Element*) const;
};