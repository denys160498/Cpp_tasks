#include "GameMap.h"
#include "Game.h"

int main()
{
	Game GameObj;
	//GameObj.draw_map();
	Element el1(12,13,'+');
	GameObj.get_snake_ptr()->add_element(&el1);
	GameObj.inscribe_snake();
	GameObj.draw_map();
	GameObj.clear_map();
	GameObj.draw_map();
}