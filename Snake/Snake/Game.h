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
	Game();
	~Game();
	void draw_map() const;
	void clear_map() const;
	void inscribe_snake();
	Snake* get_snake_ptr() const;
	Element* create_random_element();
	void draw_element_on_map(Element*);
	bool check_is_snake_on_element(Element*) const;
};