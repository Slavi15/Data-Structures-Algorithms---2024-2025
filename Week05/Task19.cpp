/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
	ListNode* reverse(ListNode* head, int k)
	{
		ListNode* curr = head, * next = nullptr, * prev = nullptr;
		int count = 0;

		ListNode* temp = head;

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

	ListNode* reverseKGroup(ListNode* head, int k)
	{
		return reverse(head, k);
	}
};