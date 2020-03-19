#include "Snake.h"

Snake::Element::Element(int x, int y, char aprnc) : positionX(x), positionY(y), appearance(aprnc)
{
}

Snake::Snake(int x, int y, char aprnc) 
{
	Element* firstElement = new Element(x, y, aprnc);
	elemList.push_back(firstElement);
}