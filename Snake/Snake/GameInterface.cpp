#include "GameInterface.h"

GameInterface::GameInterface(): GamePtr(nullptr)
{}

void GameInterface::create_game()
{
	static bool isGameCreated = false;
	//check if a Game has been already created
	if (!isGameCreated)
	{
		GamePtr = new Game;
		isGameCreated = true;
	}
}

void GameInterface::delete_game() 
{
	delete GamePtr;
}