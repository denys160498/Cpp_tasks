#include <iostream>
#include "MyStack.h"

using namespace std;

template <class T>
MyStack<T>::MyStack() :top(nullptr) {}

template <class T>
void MyStack<T>::push(T d)
{
	Node<T>* N = new Node<T>(d);
	N->setNext(top);
	top = N;
}

template <class T>
Node<T> MyStack<T>::pop()
{
	Node<T> N = *top;
	Node<T>* current = top;
	top = current->getNext();
	delete current;
	return N;
}

template <class T>
Node<T>* MyStack<T>::getTop()
{
	return top;
}

template <class T>
int MyStack<T>::printStack(Node<T>* nPtr)
{
	if (nPtr == nullptr)
	{
		return 0;
	}

	cout << nPtr->getData() << endl;
	printStack(nPtr->getNext());
}
//TODO implement deleteStack()
template <class T>
int MyStack<T>::clearStack()
{
	Node<T>* nPtr = this->top;
	if (nPtr == nullptr)
	{
		this->top = nullptr;
		return 0;
	}
	this->top = top->getNext();
	delete nPtr;
	this->clearStack();
}

