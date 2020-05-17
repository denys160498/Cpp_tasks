#include "GameInterface.h"
#include "CustomFunctions.h"

int main()
{
	GameInterface Interface;
	bool isGameToBeCreated = false;
	do
	{
		isGameToBeCreated = Interface.main_menu();

		if (isGameToBeCreated)
		{
			Interface.create_game();
			Interface.game_process();
			Interface.delete_game();
		}
	} while (isGameToBeCreated);
}