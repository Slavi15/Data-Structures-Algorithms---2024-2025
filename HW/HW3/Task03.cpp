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

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position)
{
	if (!llist) return nullptr;

	SinglyLinkedListNode* current = llist;

	while (position-- > 1) current = current->next;

	SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);

	newNode->next = current->next;
	current->next = newNode;

	return llist;
}