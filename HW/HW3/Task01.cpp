class SinglyLinkedListNode
{
public:
	int data;
	SinglyLinkedListNode* next;

	SinglyLinkedListNode(int node_data) {
		this->data = node_data;
		this->next = nullptr;
	}
};

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2)
{
	SinglyLinkedListNode* dummy = new SinglyLinkedListNode(0);
	SinglyLinkedListNode* tail = dummy;

	while (head1 != nullptr && head2 != nullptr)
	{
		if (head1->data <= head2->data)
		{
			tail->next = head1;
			head1 = head1->next;
		}
		else
		{
			tail->next = head2;
			head2 = head2->next;
		}

		tail = tail->next;
	}

	while (head1 != nullptr)
	{
		tail->next = head1;
		head1 = head1->next;
		tail = tail->next;
	}

	while (head2 != nullptr)
	{
		tail->next = head2;
		head2 = head2->next;
		tail = tail->next;
	}

	SinglyLinkedListNode* merge = dummy->next;
	delete dummy;

	return merge;
}