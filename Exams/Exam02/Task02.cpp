#include <iostream>

struct Node
{
	int val;
	Node* next;
	Node(int val) : val(val), next(nullptr) {}
	Node(int val, Node* next) : val(val), next(next) {}
};

int getLength(Node* head)
{
	int res = 0;
	while (head != nullptr && ++res) head = head->next;
	return res;
}

Node* reverse(Node* head, int k)
{
	Node* curr = head, * next = nullptr, * pre = nullptr;
	int count = 0;

	while (curr != nullptr && count < k)
	{
		next = curr->next;
		curr->next = pre;

		pre = curr;
		curr = next;

		count++;
	}

	if (next != nullptr) head->next = reverse(next, k);

	return pre;
}

Node* reverseNodes(Node* head)
{
	if (!head || !head->next) return head;

	int len = getLength(head);
	int k = (len % 2 == 0) ? (len / 2) : (len / 2) + 1;

	return reverse(head, k);
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

		while (curr->next != nullptr)
		{
			curr = curr->next;
		}

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
		push_back(node, 8);

		Node* reversed = reverseNodes(node);

		print(reversed);

		free(node);
	}
	{
		Node* node = new Node(1);
		push_back(node, 2);
		push_back(node, 3);
		push_back(node, 4);
		push_back(node, 5);
		push_back(node, 6);
		push_back(node, 7);

		Node* reversed = reverseNodes(node);

		print(reversed);

		free(node);
	}

	return 0;
}