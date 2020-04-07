#pragma once

class Element {
private: 
    char appearance;
    int positionX;
    int positionY;
public:
    Element(int, int, char aprnc = '+');
    int get_posX() const;
    int get_posY() const;
    void set_posX(int value);
    void set_posY(int value);
    char get_appearance() const;
};
