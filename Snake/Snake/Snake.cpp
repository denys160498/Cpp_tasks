#include "Snake.h"

Snake::Snake(int x, int y, char aprnc) 
{
	Element* firstElement = new Element(x, y, aprnc);
	elemList.push_back(firstElement);
}

void Snake::add_element(Element* elem)
{
	elemList.push_back(elem);
}

std::list<Element*> Snake::get_elemList()
{
	return elemList;
}