#include "Game.h"

Game::Game()
{
	Map = new GameMap;
}

Game::~Game()
{
	delete Map;
}

void Game::draw_map() const
{
	Map->draw();
}