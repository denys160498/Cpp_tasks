#pragma once
#include <vector>
#include "ELement.h"

class Snake
{
private:
    std::vector<Element*> elemList;
    char direction;
public:
    Snake(int , int, char aprnc = 'o');

    void move();
    void add_element(Element*);
    void set_direction(char);
    std::vector<Element*>* get_elemList();
    bool are_coordinates_on_snake(int , int ) const;
};