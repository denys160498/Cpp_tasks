#include "GameInterface.h"
#include "CustomFunctions.h"
#include <iostream>
#include "conio.h"

GameInterface::GameInterface() :
	GamePtr(nullptr),
	MapPtr(nullptr),
	SnakePtr(nullptr),
	mapAppearance('#'),
	mapType(mapType::STANDART),
	snakeType(snakeType::STANDART),
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
		//create a map of type specified
		if (mapType == mapType::STANDART)
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
	//check if a Snake has been already created
	if (!isSnakeCreated)
	{
		//create a snake of type specified
		if (snakeType == snakeType::STANDART)
		{
			SnakePtr = new Snake(mapAppearance, mapSizes[0], mapSizes[1]);
		}
		else
		{
			std::cout << "Invalid Type of Snake!";
			return;
		}
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

//Menu functions
char GameInterface::main_menu() const
{
	char choice = '0';
	std::string items[] = {"New game","Options","Quit"};

	do
	{
		choice = custfuncs::displayMenuItems(items, 3);
	} while (choice != '3');
	
	return choice;
}


void GameInterface::game_options()
{
	char choice = '0';

	custfuncs::setConsoleSize(20, 4);

	do
	{
		system("cls");
		std::cout << "(1) Change Map size \n";
		std::cout << "(2) Change Map appearance \n";
		std::cout << "(3) Change Map type \n";
		std::cout << "(4) Change Snake type \n";
		std::cout << "(5) <-Back \n";
		std::cout << "Make your choice: ";
		choice = _getch();
	} while (choice != '5');
}

void GameInterface::set_map_size()
{
	char choice = '0';

	custfuncs::setConsoleSize(20, 4);

	do
	{
		system("cls");
		std::cout << "(1) Small (10x10) \n";
		std::cout << "(2) Medium (25x25) \n";
		std::cout << "(3) Big (50x50) \n";
		std::cout << "(4) <-Back \n";
		std::cout << "Make your choice: ";
		choice = _getch();

		switch (choice)
		{
		case '1': 
			mapSizes[0] = 10;
			mapSizes[1] = 10;
			break;
		case '2':
			mapSizes[0] = 25;
			mapSizes[1] = 25;
			break;
		case '3':
			mapSizes[0] = 50;
			mapSizes[1] = 50;
			break;
		}
	} while (choice != '4');
}
void GameInterface::set_map_appearance()
{
	char choice = '0';

	custfuncs::setConsoleSize(20, 4);

	do
	{
		system("cls");
		std::cout << "(1) Standart (#) \n";
		std::cout << "(2) Rich ($) \n";
		std::cout << "(3) Round (o) \n";
		std::cout << "(4) Enter custom \n";
		std::cout << "(5) <-Back \n";
		std::cout << "Make your choice: ";
		choice = _getch();

		switch (choice)
		{
		case '1':
			mapAppearance = '#';
			break;
		case '2':
			mapAppearance = '$';
			break;
		case '3':
			mapAppearance = 'o';
			break;
		case '4':
			std::cout << "Enter a custom appearance: ";
			mapAppearance = _getch();
			break;
		}
	} while (choice != '5');
}