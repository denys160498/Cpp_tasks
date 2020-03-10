#include <iostream>
#include <string>
#include "MyStack.cpp"
#include "Node.cpp"

using namespace std;

int main()
{
	MyStack<int> IntStack;

	for (int i = 0; i < 6; i++)
	{
		IntStack.push(i);
	}

	IntStack.printStack(IntStack.getTop());

	return 0;
}

