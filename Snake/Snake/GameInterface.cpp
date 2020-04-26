#include "GameInterface.h"
#include "CustomFunctions.h"
#include <iostream>
#include "conio.h"

GameInterface::GameInterface() :
	GamePtr(nullptr),
	MapPtr(nullptr),
	SnakePtr(nullptr),
	mapAppearance('#'),
	mapType("STANDART"),
	snakeType("STANDART"),
	mapSizes {25,25}
{
}

void GameInterface::create_game()
{
	static bool isGameCreated = false;
	//check if a Game has been already created
	if (!isGameCreated)
	{
		try {
			GamePtr = new Game(MapPtr, SnakePtr);
			isGameCreated = true;
		}
		catch (int a)
		{
			std::cout << "[ERROR] Unable to create a Game because either Map or Snake is not created\n";
		}
	}	
}

void GameInterface::create_map()
{
	static bool isMapCreated = false;
	//check if a Map has been already created
	if (!isMapCreated)
	{
		if (mapType == "STANDART")
		{
			MapPtr = new GameMap(mapAppearance, mapSizes[0], mapSizes[1]);
		}
		else
		{
			std::cout << "Invalid Type of Map!";
			return;
		}
		isMapCreated = true;
	}
}

void GameInterface::create_snake()
{
	static bool isSnakeCreated = false;
	//check if a Map has been already created
	if (!isSnakeCreated)
	{
		SnakePtr = new Snake(mapAppearance, mapSizes[0], mapSizes[1]);
		isSnakeCreated = true;
	}
}

void GameInterface::delete_game() 
{
	delete GamePtr;
}

void GameInterface::game_process()
{
}

void GameInterface::start_game()
{
}

//TODO: finish the function
void GameInterface::game_menu()
{
	char choice;

	custfuncs::setConsoleSize(20, 4);

	do
	{
		system("cls");
		std::cout << "(1) New game \n";
		std::cout << "(2) Options \n";
		std::cout << "(3) Quit \n";
		std::cout << "Make your choice: ";
		choice = _getch();
	} while (choice != '1' && choice != '2' && choice != '3');
}