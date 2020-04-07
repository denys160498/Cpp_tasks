#include "GameMap.h"
#include "Game.h"

int main()
{
	Game GameObj;
	//GameObj.draw_map();
	Element el1(12,13,'+');
	Element el2(12, 14, '+');
	Element el3(12, 15, '+');
	GameObj.get_snake_ptr()->add_element(&el1);
	GameObj.get_snake_ptr()->add_element(&el2);
	GameObj.get_snake_ptr()->add_element(&el3);
	GameObj.inscribe_snake();
	GameObj.draw_map();
	GameObj.get_snake_ptr()->move();
	GameObj.clear_map();
	GameObj.inscribe_snake();
	GameObj.draw_map();
	GameObj.get_snake_ptr()->move();
	GameObj.clear_map();
	GameObj.inscribe_snake();
	GameObj.draw_map();
}