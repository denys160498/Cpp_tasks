#pragma once
#include "MyList.h"

template <class T>
class MyDoublyList:public MyList<T>
{
private:
	struct Node
	{
		Node(T, Node*, Node*);

		T value;
		Node* next;
		Node* prev;
	};
	Node* head;
	Node* tail;
public:
	~MyDoublyList();

	void push_back(T);
	void push_front(T);
	void pop_back();
	void pop_front();
	void print_backward() const;
	void print() const;
};