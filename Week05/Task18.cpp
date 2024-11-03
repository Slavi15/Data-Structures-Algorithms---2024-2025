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
	ListNode* swapPairs(ListNode* head)
	{
		if (head == nullptr || head->next == nullptr) return head;

		ListNode* dummy = new ListNode(0);
		ListNode* pre = dummy, * curr = head;

		while (curr && curr->next)
		{
			pre->next = curr->next;
			curr->next = pre->next->next;
			pre->next->next = curr;

			pre = curr;
			curr = curr->next;
		}

		return dummy->next;
	}
};