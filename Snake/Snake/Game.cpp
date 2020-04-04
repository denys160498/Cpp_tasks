#include "Game.h"

Game::Game()
{
	MapPtr = new GameMap;
	SnakePtr = new Snake(MapPtr->get_width() / 2, MapPtr->get_height() / 2);
}

Game::~Game()
{
	delete MapPtr;
	delete SnakePtr;
}

void Game::draw_map() const
{
	MapPtr->draw();
}

void Game::clear_map() const
{
	MapPtr->clear();
}

//draw snake on map element by element
void Game::inscribe_snake() {
	std::vector<Element*>* snakeElements = SnakePtr->get_elemList();
	std::vector<Element*>::iterator iter = (*snakeElements).begin();
	std::vector<Element*>::iterator iterEnd = (*snakeElements).end();
	while (iter != iterEnd)
	{
		//change appropriate Map cell to Element of Snake appearance
		std::vector<std::string>* mapDescription = MapPtr->get_map_ptr();
		(*mapDescription)[(*iter)->get_posX()][(*iter)->get_posY()] = (*iter)->get_appearance();
		iter++;
	}
}

Snake* Game::get_snake_ptr() const
{
	return SnakePtr;
}