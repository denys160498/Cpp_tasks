#include <iostream>
#include "MyList.h"

using namespace std;

template <class T>
MyList<T>::MyList() :head(nullptr),tail(nullptr), size(0) {}

template <class T>
MyList<T>::~MyList()
{
	this->clean_up();
}

template <class T>
MyList<T>::Node::Node(T data, Node* nextPtr): value(data), next(nextPtr) {}

template <class T>
void MyList<T>::push_back(T data)
{
	Node* nPtr = new Node(data, tail);
	tail = nPtr;

	if (size == 0)
	{ 
		head = nPtr;
	}

	size++;
}

template <class T>
void MyList<T>::push_front(T data)
{
	Node* nPtr = new Node(data, nullptr);

	if (size == 0)
	{
		head = nPtr;
		tail = nPtr;
		size++;
		return;
	}

	head->next = nPtr;
	head = nPtr;
	size++;
}

template <class T>
void MyList<T>::pop_back()
{
	if (size == 0)
	{
		return;
	}
	Node* nPtr = tail;
	tail = nPtr->next;
	delete nPtr;
	size--;
}

template <class T>
void MyList<T>::pop_front()
{
	if (size == 0)
	{
		return;
	}
	Node* hPtr = head;
	Node* tPtr = tail;
	while (tPtr != nullptr)
	{
		if (tPtr->next == head)
		{
			head = tPtr;
			head->next = nullptr;
			break;
		}
		tPtr = tPtr->next;
	}
	delete hPtr;
	size--;
}

template <class T>
void MyList<T>::print() const
{
	if (size == 0)
	{
		return;
	}
	Node* tPtr = tail;
	while (tPtr != nullptr)
	{
		cout << tPtr->value <<" ";
		tPtr = tPtr->next;
	}
}

template <class T>
void MyList<T>::clean_up()
{
	if (size == 0)
	{
		return;
	}
	Node* tPtr = tail;
	while (tPtr != nullptr)
	{
		tail = tPtr->next;
		delete tPtr;
		tPtr = tail;
		size--;
	}
}