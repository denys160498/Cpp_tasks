#pragma once
#include "Game.h"
#include "Snake.h"
#include "GameMap.h"

class GameInterface
{
public:
	enum class mapType
	{
		STANDART
	};

	enum class snakeType
	{
		STANDART
	};
private:
	char mapAppearance;
	int mapSizes[2];
	mapType mapType;
	snakeType snakeType;

	Game* GamePtr;
	Snake* SnakePtr;
	GameMap* MapPtr;
public:
	GameInterface();
	//menu functions
	char main_menu() const;
	void game_options();
	void set_map_size();
	void set_map_appearance();
	void set_map_type();
	void set_snake_type();
	//
	//game interaction functions
	void create_game();
	void create_map();
	void create_snake();
	void start_game();
	void delete_game();
	void game_process();
	//
};