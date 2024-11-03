struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	int getLength(ListNode* head)
	{
		int len = 0;

		while (head != nullptr)
		{
			len++;
			head = head->next;
		}

		return len;
	}

	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode* curr = head;

		int removeIndex = getLength(head) - n;
		int idx = 1;

		if (removeIndex - 1 == -1) return head->next;

		while (curr != nullptr)
		{
			if (idx == removeIndex) curr->next = curr->next->next;

			idx++;
			curr = curr->next;
		}

		return head;
	}
};