#pragma once
#include <vector>
#include "Element.h"

class Snake
{
private:
    std::vector<Element*> elemList;
    char direction;
    int mapWidth;
    int mapHeight;
public:
    Snake(int , int, char aprnc = 'o');
    ~Snake();
    void move();
    void add_element(Element*);
    void set_direction(char);
    std::vector<Element*>* get_elemList();
    bool are_coordinates_on_snake(int , int ) const;
};