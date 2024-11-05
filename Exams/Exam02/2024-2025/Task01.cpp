#include <iostream>

struct Node
{
	int val;
	Node* next;
	Node(int val) : val(val), next(nullptr) {}
	Node(int val, Node* next) : val(val), next(next) {}
};

Node* deleteNodes(Node* head, int x)
{
	if (!head || !head->next) return head;

	Node* curr = head, * pre = head;

	while (curr != nullptr)
	{
		if (curr && curr->val % x == 0)
		{
			while (curr && curr->val % x == 0)
			{
				curr = curr->next;
			}

			pre->next = curr;
		}
		else
		{
			pre = curr;
		}

		curr = curr->next;
	}

	return head;
}

void push_back(Node*& head, int value)
{
	Node* newNode = new Node(value);

	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		Node* curr = head;
		while (curr->next != nullptr) curr = curr->next;
		curr->next = newNode;
	}
}

void print(Node* head)
{
	Node* curr = head;

	while (curr != nullptr)
	{
		std::cout << curr->val << " ";
		curr = curr->next;
	}

	std::cout << std::endl;
}

void free(Node* head)
{
	Node* curr = head;

	while (curr != nullptr)
	{
		Node* toDelete = curr;
		curr = curr->next;
		delete toDelete;
	}
}

int main()
{
	{
		Node* node = new Node(1);
		push_back(node, 2);
		push_back(node, 3);
		push_back(node, 4);
		push_back(node, 5);
		push_back(node, 6);
		push_back(node, 7);

		deleteNodes(node, 3);

		print(node);

		free(node);
	}
	{
		Node* node = new Node(8);
		push_back(node, 5);
		push_back(node, 3);
		push_back(node, 5);
		push_back(node, 5);
		push_back(node, 5);
		push_back(node, 1);
		push_back(node, 7);

		deleteNodes(node, 5);

		print(node);

		free(node);
	}

	return 0;
}