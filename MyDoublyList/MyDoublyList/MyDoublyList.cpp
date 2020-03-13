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

	this->head->next = nPtr;
	nPtr->prev = this->head;
	this->head = nPtr;

	if (this->size == 1)
	{
		this->tail = this->head->prev;
	}

	this->size++;
}

template <class T>
void MyDoublyList<T>::push_back(T data) // TODO: Fix the function
{
	Node* nPtr = new Node(data, this->tail, nullptr);
	
	if (this->size == 0)
	{
		this->head = nPtr;
		this->tail = nPtr;
		return;
	}

	this->tail->prev = nPtr;
	this->tail = nPtr;

	if (this->size == 1)
	{
		this->head = this->tail->next;
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
	Node* tPtr = this->tail;
	while (tPtr != nullptr)
	{
		std::cout << tPtr->value << " ";
		tPtr = tPtr->next;
	}
}

template <class T>
void MyDoublyList<T>::clean_up()
{
	Node* tPtr = this->tail;
	while (tPtr != nullptr)
	{
		tail = tPtr->next;
		delete tPtr;
		tPtr = tail;
		size--;
	}
}