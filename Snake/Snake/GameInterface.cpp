#include "GameInterface.h"

GameInterface::GameInterface(): GamePtr(nullptr)
{}

Game* GameInterface::create_game()
{
	static bool isGameCreated = false;
	//check if a Game has been already created
	if (!isGameCreated)
	{
		GamePtr = new Game;
		isGameCreated = true;
	}
}