#pragma once
#include "Game.h"

class GameInterface
{
private:
	Game* GamePtr;
public:
	GameInterface();
	void create_game();
	void delete_game();
};