#include "Game.h"

Game::Game()
{
	Map = new GameMap;
	SnakePtr = new Snake(Map->get_width() / 2, Map->get_height() / 2);
}

Game::~Game()
{
	delete Map;
	delete SnakePtr;
}

void Game::draw_map() const
{
	Map->draw();
}

//TODO: Fix the assertion problem with the iterator
//draw snake on map element by element
void Game::inscribe_snake() {
	auto iter = SnakePtr->get_elemList().begin();
	while (iter != SnakePtr->get_elemList().end())
	{
		//change appropriate Map cell to Element of Snake appearance
		Map->get_map_ptr()[(*iter)->get_posX()][(*iter)->get_posY()] = (*iter)->get_appearance();
		iter++;
	}
}