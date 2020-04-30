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

//Menu functions
char GameInterface::main_menu() const
{
	char choice = '0';
	std::string items[] = {"New game","Options","Quit"};
	//Getting the number of last (quit) option
	char quitChar = sizeof(items) / sizeof(*items) + '0';

	do
	{
		choice = custfuncs::displayMenuItems(items, sizeof(items) / sizeof(*items));
	} while (choice != quitChar);
	
	return choice;
}


void GameInterface::game_options()
{
	char choice = '0';
	std::string items[] = { "Change Map size","Change Map appearance","Change Map type","Change Snake type","<-Back"};
	//Getting the number of last (quit) option
	char quitChar = sizeof(items) / sizeof(*items) + '0';

	do
	{
		choice = custfuncs::displayMenuItems(items, sizeof(items) / sizeof(*items));

		switch (choice)
		{
		case '1':
			this->select_map_size();
			break;
		case '2':
			this->select_map_appearance();
			break;
		case '3':
			this->select_map_type();
			break;
		case '4':
			this->select_snake_type();
			break;
		}
	} while (choice != quitChar);
}

void GameInterface::select_map_size()
{
	char choice = '0';
	std::string items[] = { "Small (10x10)","Medium (25x25)","Big (50x50)","<-Back"};
	//Getting the number of last (quit) option
	char quitChar = sizeof(items) / sizeof(*items) + '0';

	do
	{
		choice = custfuncs::displayMenuItems(items, sizeof(items) / sizeof(*items));

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
	} while (choice != quitChar);
}

void GameInterface::select_map_appearance()
{
	char choice = '0';
	std::string items[] = { "Standart (#)","Rich ($)","Round (o)","Enter custom","<-Back" };
	//Getting the number of last (quit) option
	char quitChar = sizeof(items) / sizeof(*items) + '0';

	do
	{
		choice = custfuncs::displayMenuItems(items, sizeof(items) / sizeof(*items));

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
	} while (choice != quitChar);
}

void GameInterface::select_map_type()
{
	char choice = '0';
	std::string items[] = { "Standart","<-Back"};
	//Getting the number of last (quit) option
	char quitChar = sizeof(items) / sizeof(*items) + '0';

	do
	{
		choice = custfuncs::displayMenuItems(items, sizeof(items)/sizeof(*items));

		switch (choice)
		{
		case '1':
			mapType = mapType::STANDART;
			break;
		}
	} while (choice != quitChar);
}

void GameInterface::select_snake_type()
{
	char choice = '0';
	std::string items[] = { "Standart","<-Back" };
	//Getting the number of last (quit) option
	char quitChar = sizeof(items) / sizeof(*items) + '0';

	do
	{
		choice = custfuncs::displayMenuItems(items, sizeof(items) / sizeof(*items));

		switch (choice)
		{
		case '1':
			snakeType = snakeType::STANDART;
			break;
		}
	} while (choice != quitChar);
}