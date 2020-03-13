#include <iostream>
#include "MyDoublyList.cpp"

using namespace std;

int main()
{
	MyDoublyList<int> MList;

	for (int i = 0; i < 3; i++)
	{
		MList.push_front(i);
	}

	MList.print();
	cout << endl;
	MList.print_backward();

	for (int i = 3; i < 6; i++)
	{
		MList.push_back(i);
	}

	cout << endl;
	MList.print();
	cout << endl;
	MList.print_backward();

	MList.pop_back();

	cout << endl;
	MList.print();
	cout << endl;
	MList.print_backward();

	MList.pop_front();

	cout << endl;
	MList.print();
	cout << endl;
	MList.print_backward();
}