struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
	ListNode* deleteDuplicates(ListNode* head)
	{
		ListNode* current = head;

		while (current != nullptr)
		{
			ListNode* runner = current;

			while (runner->next && runner->next->val == current->val) runner = runner->next;

			current->next = runner->next;
			current = current->next;
		}

		return head;
	}
};