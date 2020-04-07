#include "Snake.h"
#include <cctype>

Snake::Snake(int x, int y, char aprnc): direction('W')
{
	Element* firstElement = new Element(x, y, aprnc);
	elemList.push_back(firstElement);
}

void Snake::add_element(Element* elem)
{
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
		elemList[0]->set_posX(elemList[0]->get_posX() - 1);
		break;
	case 'S':
		elemList[0]->set_posX(elemList[0]->get_posX() + 1);
		break;
	case 'A':
		elemList[0]->set_posY(elemList[0]->get_posY() - 1);
		break;
	case 'D':
		elemList[0]->set_posY(elemList[0]->get_posY() + 1);
		break;
	default:
		break;
	}

	//move the others elements
	auto iter = elemList.begin()+1;
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
	// 'if' is to prevent setting the direction backwards
	if ((direction == 'W' && dir == 'S') || (direction == 'D' && dir == 'A') || (direction == 'S' && dir == 'W') || (direction == 'A' && dir == 'D')) 
	{
		return;
	}
	direction = dir;
}