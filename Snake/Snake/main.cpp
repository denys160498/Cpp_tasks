#include "GameInterface.h"
#include "CustomFunctions.h"

int main()
{
	std::string items[] = {"One","Two","Three","Four"};
	char choice = '0';
	do {
		choice = custfuncs::displayMenuItems(items, 4);
	} while (choice != '4');
		/*
	GameObj.get_snake_ptr()->set_direction('d');

	for (int i = 0; i < 15; i++)
	{
		GameObj.clear_map();
		GameObj.get_snake_ptr()->move();
		GameObj.inscribe_snake();
		GameObj.draw_map();
	}*/
	//GameObj.draw_map();
	/*
	Element el1(12, 12);
	Element el2(12, 12);
	Element el3(12, 12);
	Element el4(12, 12);
	GameObj.get_snake_ptr()->add_element(&el1);
	GameObj.get_snake_ptr()->add_element(&el2);
	GameObj.get_snake_ptr()->add_element(&el3);
	GameObj.inscribe_snake();
	GameObj.draw_element_on_map(GameObj.create_random_element());
	GameObj.draw_map();
	GameObj.get_snake_ptr()->move();
	GameObj.get_snake_ptr()->set_direction('a');
	GameObj.clear_map();
	GameObj.inscribe_snake();
	GameObj.draw_element_on_map(GameObj.create_random_element());
	GameObj.draw_map();
	GameObj.get_snake_ptr()->move();
	GameObj.get_snake_ptr()->add_element(&el4);
	GameObj.clear_map();
	GameObj.inscribe_snake();
	GameObj.draw_element_on_map(GameObj.create_random_element());
	GameObj.draw_map();*/
}