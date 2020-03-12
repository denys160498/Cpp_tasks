#include "MyDoublyList.h"
#include <iostream>



template <class T>
MyDoublyList<T>::~MyDoublyList()
{
	this->clean_up();
}

template <class T>
MyDoublyList<T>::Node::Node(T data, Node* nextPtr, Node* prevPtr) : value(data), next(nextPtr), prev(prevPtr) {}

template <class T>
void MyDoublyList<T>::push_front(T data)
{
	Node* nPtr = new Node(data, nullptr, this->head);

	if (this->size == 0)
	{
		this->head = nPtr;
		this->tail = nPtr;
		this->size++;
		return;
	}

	this->head->next = nPtr; //problem here
	nPtr->prev = this->head;
	this->head = nPtr;
	this->size++;
}

template <class T>
void MyDoublyList<T>::push_back(T data)
{
	Node* nPtr = new Node(data, this->tail, nullptr);
	this->tail = nPtr;

	if (this->size == 0)
	{
		this->head = nPtr;
	}

	this->size++;
}

template <class T>
void MyDoublyList<T>::pop_back()
{
	if (this->size == 0)
	{
		return;
	}
	Node* nPtr = this->tail;
	this->tail = nPtr->next;
	this->tail->prev = nullptr;
	delete nPtr;
	this->size--;
}

template <class T>
void MyDoublyList<T>::pop_front()
{
	if (this->size == 0)
	{
		return;
	}
	Node* nPtr = this->head;
	this->head = nPtr->prev;
	this->head->next = nullptr;
	delete nPtr;
	this->size--;
}

template <class T>
void MyDoublyList<T>::print_backward() const
{
	if (this->size == 0)
	{
		return;
	}
	Node* tPtr = this->head;
	while (tPtr != nullptr)
	{
		std::cout << tPtr->value << " ";
		tPtr = tPtr->prev;
	}
}

template <class T>
void MyDoublyList<T>::print() const
{
	if (this->size == 0)
	{
		return;
	}
	Node* tPtr = this->tail;
	while (tPtr != nullptr)
	{
		std::cout << tPtr->value << " ";
		tPtr = tPtr->next;
	}
}