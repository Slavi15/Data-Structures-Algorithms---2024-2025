#include <iostream>

#define TT template <typename T>

TT
class SinglyLinkedList
{
private:
	struct Node
	{
		T data;
		Node* next;

		Node(const T& data) : data(data), next(nullptr) {}
	};

	Node* head;
	Node* tail;

	void copyFrom(const SinglyLinkedList<T>& other);
	void free();

public:
	SinglyLinkedList();

	SinglyLinkedList(const SinglyLinkedList<T>& other);
	SinglyLinkedList& operator=(const SinglyLinkedList<T>& other);

	void push_back(const T& element);
	void push_front(const T& element);

	void pop_front();

	const T& front() const;
	const T& back() const;

	bool isEmpty() const;
	void print() const;

	~SinglyLinkedList() noexcept;
};

TT
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr), tail(nullptr) {}

TT
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T>& other)
{
	copyFrom(other);
}

TT
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(const SinglyLinkedList<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

TT
void SinglyLinkedList<T>::push_back(const T& element)
{
	Node* newNode = new Node(element);

	if (!tail)
	{
		this->head = this->tail = newNode;
		return;
	}

	tail->next = newNode;
	tail = newNode;
}

TT
void SinglyLinkedList<T>::push_front(const T& element)
{
	Node* newNode = new Node(element);

	if (!head)
	{
		head = tail = newNode;
		return;
	}

	newNode->next = head;
	head = newNode;
}

TT
void SinglyLinkedList<T>::pop_front()
{
	if (!head) return;

	if (head == tail)
	{
		delete head;
		head = tail = nullptr;
		return;
	}

	Node* toDelete = head;
	head = head->next;
	delete toDelete;
}

TT
const T& SinglyLinkedList<T>::front() const
{
	if (!head)
		throw std::runtime_error("No head found!");

	return head->data;
}

TT
const T& SinglyLinkedList<T>::back() const
{
	if (!tail)
		throw std::runtime_error("No tail found!");

	return tail->data;
}

TT
bool SinglyLinkedList<T>::isEmpty() const
{
	return head == nullptr && tail == nullptr;
}

TT
void SinglyLinkedList<T>::print() const
{
	Node* iter = head;

	while (iter)
	{
		std::cout << iter->data << " ";

		if (iter->next) std::cout << "-> ";

		iter = iter->next;
	}

	std::cout << std::endl;
}

TT
SinglyLinkedList<T>::~SinglyLinkedList() noexcept
{
	free();
}

TT
void SinglyLinkedList<T>::copyFrom(const SinglyLinkedList<T>& other)
{
	Node* iter = other.head;

	while (iter)
	{
		push_back(iter->data);
		iter = iter->next;
	}
}

TT
void SinglyLinkedList<T>::free()
{
	Node* iter = head;

	while (iter)
	{
		Node* toDelete = iter;
		iter = iter->next;
		delete toDelete;
	}
}
