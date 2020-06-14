#include "Snake.h"
#include <cctype>

Snake::Snake(int mapW, int mapH, char aprnc): direction('W'), mapWidth(mapW), mapHeight(mapH)
{
	Element* firstElement = new Element(mapW / 2, mapH / 2, aprnc);
	Element* secondElement = new Element(mapW / 2, mapH / 2);
	Element* thirdElement = new Element(mapW / 2, mapH / 2);
	elemList.push_back(firstElement);
	this->add_element(secondElement);
	this->add_element(thirdElement);
}

Snake::~Snake()
{
	std::vector<Element*>::iterator iter = elemList.begin();
	while (iter != elemList.end())
	{
		delete* iter;
		iter++;
	}
	elemList.clear();
}
//TODO: Add a handling of addition element on border position
void Snake::add_element(Element* elem)
{
	switch (direction)
	{
	case 'W':
		elem->set_posX(elemList.back()->get_posX());
		elem->set_posY(elemList.back()->get_posY() + 1);
		break;
	case 'S':
		elem->set_posX(elemList.back()->get_posX());
		elem->set_posY(elemList.back()->get_posY() - 1);
		break;
	case 'A':
		elem->set_posX(elemList.back()->get_posX() + 1);
		elem->set_posY(elemList.back()->get_posY());
		break;
	case 'D':
		elem->set_posX(elemList.back()->get_posX() - 1);
		elem->set_posY(elemList.back()->get_posY());
		break;
	default:
		break;
	}
	elemList.push_back(elem);
}

std::vector<Element*>* Snake::get_elemList()
{
	return &elemList;
}

void Snake::move() 
{
	int currElementPosX;
	int currElementPosY;
	int prevElementPosX = elemList[0]->get_posX();
	int prevElementPosY = elemList[0]->get_posY();

	//move the head element
	switch (direction)
	{
	case 'W':
		elemList[0]->set_posY(elemList[0]->get_posY() - 1);
		//check if on upper border
		if (elemList[0]->get_posY() < 1)
		{
			elemList[0]->set_posY(mapHeight - 1);
		}
		break;
	case 'S':
		elemList[0]->set_posY(elemList[0]->get_posY() + 1);
		//check if on bottom border
		if (elemList[0]->get_posY() > mapHeight - 1)
		{
			elemList[0]->set_posY(1);
		}
		break;
	case 'A':
		elemList[0]->set_posX(elemList[0]->get_posX() - 1);
		//check if on left border
		if (elemList[0]->get_posX() < 1)
		{
			elemList[0]->set_posX(mapWidth - 1);
		}
		break;
	case 'D':
		elemList[0]->set_posX(elemList[0]->get_posX() + 1);
		//check if on right border
		if (elemList[0]->get_posX() > mapWidth - 1)
		{
			elemList[0]->set_posX(1);
		}
		break;
	default:
		break;
	}

	//move the others elements
	auto iter = elemList.begin() + 1;
	while (iter != elemList.end())
	{
		currElementPosX = (*iter)->get_posX();
		currElementPosY = (*iter)->get_posY();
		(*iter)->set_posX(prevElementPosX);
		(*iter)->set_posY(prevElementPosY);
		prevElementPosX = currElementPosX;
		prevElementPosY = currElementPosY;
		iter++;
	}
}

void Snake::set_direction(char dir) 
{
	dir = std::toupper(dir);
	// 'if' is to prevent setting the backward direction and setting invalid direction
	if (((direction == 'W' && dir == 'S') || (direction == 'D' && dir == 'A') || (direction == 'S' && dir == 'W') || (direction == 'A' && dir == 'D')) || (dir != 'W' && dir != 'S' && dir != 'A' && dir != 'D'))
	{
		return;
	}

	direction = dir;
}

bool Snake::are_coordinates_on_snake(int x, int y) const
{
	bool isOnSnake = false;
	auto iter = elemList.begin();
	while (iter != elemList.end())
	{
		if ((*iter)->get_posX() == x && (*iter)->get_posY() == y)
		{
			isOnSnake = true;
			break;
		}
		iter++;
	}
	return isOnSnake;
}