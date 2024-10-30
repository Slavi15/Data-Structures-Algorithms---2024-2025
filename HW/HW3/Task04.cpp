#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

struct Node
{
	int data;
	Node* next = nullptr;

	Node(int data) : data(data) {}
};

void insertNode(Node*& head, int data)
{
	Node* newNode = new Node(data);

	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		Node* temp = head;
		while (temp->next != nullptr) temp = temp->next;
		temp->next = newNode;
	}
}

Node* reverse(Node* head, int k)
{
	Node* curr = head, * prev = nullptr, * next = nullptr;
	int count = 0;

	Node* temp = head;

	for (int i = 0; i < k; i++)
	{
		if (temp == nullptr) return head;
		temp = temp->next;
	}

	while (curr != nullptr && count < k)
	{
		next = curr->next;
		curr->next = prev;

		prev = curr;
		curr = next;

		count++;
	}

	if (next != nullptr) head->next = reverse(next, k);

	return prev;
}

void print(Node* list)
{
	while (list != nullptr)
	{
		std::cout << list->data << " ";
		list = list->next;
	}
}

int main()
{
	int N = 0;
	std::cin >> N;

	Node* list = nullptr;

	for (int i = 0; i < N; i++)
	{
		int data;
		std::cin >> data;
		insertNode(list, data);
	}

	int k = 0;
	std::cin >> k;

	list = reverse(list, k);

	print(list);

	return 0;
}