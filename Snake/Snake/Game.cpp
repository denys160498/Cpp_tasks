#include "Game.h"
#include <cstdlib>

Game::Game(GameMap* Map, Snake* GameSnake): MapPtr(Map), SnakePtr(GameSnake)
{
	if (Map == nullptr || GameSnake == nullptr)
	{
		throw 1;
	}
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

bool Game::check_is_snake_on_element(Element* elem) const
{
	Element* snakeHead = (*SnakePtr->get_elemList())[0];
	bool isSnakeHeadOnElement = false;

	if (snakeHead->get_posX() == elem->get_posX() && snakeHead->get_posY() == elem->get_posY())
	{
		isSnakeHeadOnElement = true;
	}

	return isSnakeHeadOnElement;
}