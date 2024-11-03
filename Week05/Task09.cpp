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
	ListNode* reverseBetween(ListNode* head, int left, int right)
	{
		ListNode* dummy = new ListNode(0, head);
		ListNode* pre = dummy;

		// we get node just before left
		for (int i = 0; i < left - 1; i++) pre = pre->next;

		// exactly node left
		ListNode* curr = pre->next;

		for (int i = 0; i < right - left; i++)
		{
			ListNode* forw = curr->next;
			curr->next = forw->next;
			forw->next = pre->next;
			pre->next = forw;
		}

		return dummy->next;
	}
};