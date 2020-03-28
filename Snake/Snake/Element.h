#pragma once

class Element {
private: 
    char appearance;
    int positionX;
    int positionY;
public:
    Element(int, int, char aprnc = '*');
    int get_posX() const;
    int get_posY() const;
    char get_appearance() const;
};
