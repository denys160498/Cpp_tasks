#pragma once
#include <list>
#include "ELement.h"

class Snake
{
private:
    std::list<Element*> elemList;
public:
    Snake(int , int, char aprnc = '*');

    void move();
    void add_element(Element*);
    std::list<Element*> get_elemList();
};