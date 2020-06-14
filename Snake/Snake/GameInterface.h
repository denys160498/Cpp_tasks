#pragma once
#include "Game.h"
#include "Snake.h"
#include "GameMap.h"
#include "CustomFunctions.h"
#include <iostream>
#include "conio.h"

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
	bool main_menu(); //returns TRUE if a player selected 'New Game' and a Game is to be created
	void game_options();
	void select_map_size();
	void select_map_appearance();
	void select_map_type();
	void select_snake_type();
	//
	//game interaction functions
	void create_game();
	void create_map();
	void create_snake();
	void delete_game();
	void game_process();
	//
};