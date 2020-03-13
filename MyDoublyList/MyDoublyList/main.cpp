#include <iostream>
#include "MyDoublyList.cpp"
#include "MyList.cpp"

using namespace std;

int main()
{
	MyDoublyList<int> MList;

	for (int i = 0; i < 3; i++)
	{
		MList.push_front(i);
	}

	for (int i = 3; i < 6; i++)
	{
		MList.push_back(i);
	}
	/*
	MList.pop_back();
	MList.pop_front();
	*/
	MList.print();
	cout << endl;
	MList.print_backward();
}