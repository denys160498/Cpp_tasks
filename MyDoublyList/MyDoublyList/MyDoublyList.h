#pragma once
#include "MyList.h"

template <class T>
class MyDoublyList:MyList<T>
{
private:
	struct Node
	{
		Node(T, Node*, Node*);

		T value;
		Node* next;
		Node* prev;
	};
public:
	MyDoublyList();
	~MyDoublyList();

	void push_back(T);
	void push_front(T);
	void pop_back();
	void pop_front();
	void print() const;
	void clean_up();
};