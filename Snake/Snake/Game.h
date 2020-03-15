#pragma once
#include "GameMap.h"

class Game 
{
private:	
	GameMap* Map;
public:
	Game();
	~Game();
	void draw_map() const;
};