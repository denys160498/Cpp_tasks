#include "GameInterface.h"

GameInterface::GameInterface() :
	GamePtr(nullptr),
	MapPtr(nullptr),
	SnakePtr(nullptr),
	mapAppearance('#'),
	mapType(mapType::STANDART),
	snakeType(snakeType::STANDART),
	mapSizes {10,10}
{
}

void GameInterface::create_game()
{
	//check if a Game hasn`t been already created
	if (GamePtr == nullptr)
	{
		try {
			custfuncs::createNewWindow();
			custfuncs::setConsoleSize(mapSizes[0] * 2, mapSizes[1]);
			this->create_map();
			this->create_snake();
			GamePtr = new Game(MapPtr, SnakePtr);
		}
		catch (int a)
		{
			std::cout << "[ERROR] Unable to create a Game because either a Map or a Snake is not created\n";
		}
	}
}

void GameInterface::create_map()
{
	//check if a Map hasn`t been already created
	if (MapPtr == nullptr)
	{
		//create a map of type specified
		switch (mapType)
		{
		case mapType::STANDART: 
			MapPtr = new GameMap(mapAppearance, mapSizes[0], mapSizes[1]); break;
		default:
			std::cout << "[ERROR] Invalid Type of Map!";
			return;
		}
	}
}

void GameInterface::create_snake()
{
	//check if a Snake hasn`t been already created
	if (SnakePtr == nullptr)
	{
		//create a snake of type specified
		switch (snakeType)
		{
		case snakeType::STANDART:
			SnakePtr = new Snake(mapSizes[0], mapSizes[1]); break;
		default:
			std::cout << "[ERROR] Invalid Type of Snake!";
			return;
		}
	}
}

void GameInterface::delete_game() 
{
	custfuncs::deleteCurrentWindow();
	delete SnakePtr;
	delete MapPtr;
	delete GamePtr;
	SnakePtr = nullptr;
	MapPtr = nullptr;
	GamePtr = nullptr;
}

void GameInterface::game_process()
{
	Element* randomElement = GamePtr->create_random_element();
	char direction = 'W';

	while (direction != 'e' && direction != 'E')
	{
		time_t prevtime;
		time_t currtime;

		MapPtr->clear();

		GamePtr->inscribe_snake_on_map();
		MapPtr->inscribe_element(randomElement);
		MapPtr->draw();

		prevtime = time(NULL);
		while (!_kbhit())
		{
			currtime = time(NULL);
			if (difftime(currtime, prevtime) > 0)
			{
				break;
			}
		}

		if (_kbhit())
		{
			direction = _getch();
			Sleep(750);
		}

		SnakePtr->set_direction(direction);
		SnakePtr->move();
		
		if (GamePtr->check_for_game_over())
		{
			std::cout << "GAME OVER!\n";
			system("pause");
			break;
		}

		if (GamePtr->check_is_snake_on_element(randomElement))
		{
			SnakePtr->add_element(randomElement);
			randomElement = GamePtr->create_random_element();
		}
	}
}

//Menu functions
bool GameInterface::main_menu()
{
	char choice = '0';
	bool isGameToBeCreated = false;
	std::string items[] = {"New game","Options","Quit"};
	//Getting the number of last (quit) option
	char quitChar = sizeof(items) / sizeof(*items) + '0';

	do
	{
		choice = custfuncs::displayMenuItems(items, sizeof(items) / sizeof(*items));

		switch (choice)
		{
		case '1':
			isGameToBeCreated = true;
			break;
		case '2':
			this->game_options();
			break;
		}
	} while (choice != quitChar && choice != '1');
	
	return isGameToBeCreated;
}

void GameInterface::game_options()
{
	char choice = '0';
	std::string items[] = { "Change Map size","Change Map appearance","Change Map type","Change Snake type","<-Back"};
	//Getting the number of last (quit) option
	char quitChar = sizeof(items) / sizeof(*items) + '0';

	do
	{
		choice = custfuncs::displayMenuItems(items, sizeof(items) / sizeof(*items), "Options:");

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
	std::string items[] = { "Small (8x8)","Medium (10x10)","Big (12x12)","<-Back"};
	//Getting the number of last (quit) option
	char quitChar = sizeof(items) / sizeof(*items) + '0';

	do
	{
		choice = custfuncs::displayMenuItems(items, sizeof(items) / sizeof(*items), "Select map size:");

		switch (choice)
		{
		case '1': 
			mapSizes[0] = 8;
			mapSizes[1] = 8;
			break;
		case '2':
			mapSizes[0] = 10;
			mapSizes[1] = 10;
			break;
		case '3':
			mapSizes[0] = 12;
			mapSizes[1] = 12;
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
		choice = custfuncs::displayMenuItems(items, sizeof(items) / sizeof(*items), "Select map appearance:");

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
		choice = custfuncs::displayMenuItems(items, sizeof(items)/sizeof(*items), "Select map type:");

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
		choice = custfuncs::displayMenuItems(items, sizeof(items) / sizeof(*items), "Select snake type:");

		switch (choice)
		{
		case '1':
			snakeType = snakeType::STANDART;
			break;
		}
	} while (choice != quitChar);
}