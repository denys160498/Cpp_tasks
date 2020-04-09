#include "Game.h"
#include <cstdlib>

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
		MapPtr->draw_element(*iter);
		iter++;
	}
}

Snake* Game::get_snake_ptr() const
{
	return SnakePtr;
}

//TODO: Think of separation of drawing the spawned element on map.
Element* Game::create_random_element()
{
	int x, y;
	//loop is to prevent creation of an element on snake
	do
	{
		//generate random coordinates
		x = rand() % (MapPtr->get_width() - 1) + 1;
		y = rand() % (MapPtr->get_height() - 1) + 1;
	} 
	while (SnakePtr->are_coordinates_on_snake(x, y));
	Element* elem = new Element(x, y);
	return elem;
}

void Game::draw_element_on_map(Element* elem)
{
	MapPtr->draw_element(elem);
}