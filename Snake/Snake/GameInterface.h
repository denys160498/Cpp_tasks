#pragma once
#include "Game.h"

class GameInterface
{
private:
	Game* GamePtr;
public:
	GameInterface();
	Game* create_game();
	void delete_game();
};