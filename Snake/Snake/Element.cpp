#include "Element.h"

Element::Element(int x, int y, char aprnc) : positionX(x), positionY(y), appearance(aprnc)
{}


int Element::get_posX() const
{
	return this->positionX;
}

int Element::get_posY() const
{
	return this->positionY;
}

char Element::get_appearance() const
{
	return this->appearance;
}