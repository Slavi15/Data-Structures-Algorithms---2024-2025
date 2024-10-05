#pragma once

#include <iostream>

#define TT template <typename T>

TT
class DoublyLinkedList
{
private:
	struct Node
	{
		T data;
		Node* prev;
		Node* next;

		Node(const T& data) : data(data), prev(nullptr), next(nullptr) {}
	};

	Node* head;
	Node* tail;

	size_t size;

	void copyFrom(const DoublyLinkedList<T>& other);
	void free();

public:
	DoublyLinkedList();

	DoublyLinkedList(const DoublyLinkedList<T>& other);
	DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& other);

	void push_back(const T& element);
	void push_front(const T& element);

	void pop_back();
	void pop_front();

	const T& front() const;
	const T& back() const;

	bool isEmpty() const;
	void print() const;

	~DoublyLinkedList() noexcept;
};

TT
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

TT
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& other)
{
	copyFrom(other);
}

TT
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

TT
void DoublyLinkedList<T>::push_back(const T& element)
{
	Node* newNode = new Node(element);
	size++;

	if (isEmpty())
	{
		head = tail = newNode;
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}

TT
void DoublyLinkedList<T>::push_front(const T& element)
{
	Node* newNode = new Node(element);
	size++;

	if (isEmpty())
	{
		head = tail = newNode;
	}
	else
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
}

TT
void DoublyLinkedList<T>::pop_back()
{
	if (isEmpty())
		throw std::runtime_error("Empty!");

	size--;

	if (head == tail)
	{
		delete tail;
		head = tail = nullptr;
	}
	else
	{
		Node* toDelete = tail;

		tail = tail->prev;

		delete toDelete;
		tail->next = nullptr;
	}
}

TT
void DoublyLinkedList<T>::pop_front()
{
	if (isEmpty())
		throw std::runtime_error("Empty!");

	size--;

	if (head == tail)
	{
		delete head;
		head = tail = nullptr;
	}
	else
	{
		Node* toDelete = head;

		head = head->next;

		delete toDelete;
		head->prev = nullptr;
	}
}

TT
const T& DoublyLinkedList<T>::front() const
{
	if (!head)
		throw std::runtime_error("No head!");

	return head->data;
}

TT
const T& DoublyLinkedList<T>::back() const
{
	if (!tail)
		throw std::runtime_error("No back!");

	return tail->data;
}

TT
bool DoublyLinkedList<T>::isEmpty() const
{
	return head == nullptr && tail == nullptr;
}

TT
void DoublyLinkedList<T>::print() const
{
	Node* iter = head;

	while (iter != nullptr)
	{
		std::cout << iter->data << " <-> ";
		iter = iter->next;
	}

	std::cout << std::endl;
}

TT
DoublyLinkedList<T>::~DoublyLinkedList() noexcept
{
	free();
}

TT
void DoublyLinkedList<T>::copyFrom(const DoublyLinkedList<T>& other)
{
	Node* iter = other.head;

	while (iter != nullptr)
	{
		push_back(iter->data);
		iter = iter->next;
	}
}

TT
void DoublyLinkedList<T>::free()
{
	Node* iter = this->head;

	while (iter != nullptr)
	{
		Node* toDelete = iter;
		iter = iter->next;
		delete toDelete;
	}

	head = tail = nullptr;
}
