#pragma once
#include <vector>
#include "ELement.h"

class Snake
{
private:
    std::vector<Element*> elemList;
public:
    Snake(int , int, char aprnc = 'o');

    void move();
    void add_element(Element*);
    std::vector<Element*>* get_elemList();
};