#include <iostream>
#include "MyList.cpp"

using namespace std;

int main()
{
	MyList<int> CList;

	for (int i = 5; i < 10; i++)
	{
		CList.push_front(i);
	}
	
	CList.print();
	cout << endl;

	for (int i = 4; i >= 0; i--)
	{
		CList.push_back(i);
	}

	CList.print();
	cout << endl;

	CList.pop_front();

	CList.print();
	cout << endl;

	CList.clean_up();

	CList.print();
	cout << endl;
}