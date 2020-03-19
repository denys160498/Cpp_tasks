#pragma once
#include <list>

class Snake
{
private:
    struct Element
    {
        Element(int, int, char aprnc = '*');
        char appearance;
        int positionX;
        int positionY;
    };
    std::list<Element*> elemList;
public:
    Snake(int , int, char aprnc = '*');

    void move();
    void add_element(Element*);
};