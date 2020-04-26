#pragma once
#include "Game.h"
#include "Snake.h"
#include "GameMap.h"

class GameInterface
{
private:
	char mapAppearance;
	int mapSizes[2];
	char mapType[20];
	char snakeType[20];

	Game* GamePtr;
	Snake* SnakePtr;
	GameMap* MapPtr;
public:
	GameInterface();
	void game_menu();
	void create_game();
	void create_map();
	void create_snake();
	void start_game();
	void delete_game();
	void game_process();
	void configure_game();
};