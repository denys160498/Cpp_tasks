#include "Game.h"

Game::Game()
{
	Map = new GameMap;
	SnakeObj = new Snake(Map->get_width() / 2, Map->get_height() / 2);
}

Game::~Game()
{
	delete Map;
	delete SnakeObj;
}

void Game::draw_map() const
{
	Map->draw();
}