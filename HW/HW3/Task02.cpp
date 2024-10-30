class SinglyLinkedListNode
{
public:
	int data;
	SinglyLinkedListNode* next;

	SinglyLinkedListNode(int node_data)
	{
		this->data = node_data;
		this->next = nullptr;
	}
};

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist)
{
	if (!llist) return nullptr;

	SinglyLinkedListNode* current = llist;

	while (current != nullptr) {
		SinglyLinkedListNode* runner = current;

		while (runner->next && runner->next->data == current->data) runner = runner->next;

		current->next = runner->next;
		current = current->next;
	}

	return llist;
}