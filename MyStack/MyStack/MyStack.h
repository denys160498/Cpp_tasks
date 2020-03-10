#pragma once
#include "Node.h"

template <class T>
class MyStack
{
	Node<T>* top;
public:
	MyStack();
	void push(T);
	Node<T> pop();
	Node<T>* getTop();
	int printStack(Node<T>* nPtr);
	int clearStack();
}; 