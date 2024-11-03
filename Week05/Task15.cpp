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
	ListNode* removeElements(ListNode* head, int val)
	{
		while (head && head->val == val) head = head->next;

		if (head == nullptr) return head;

		ListNode* pre = head, * curr = head->next;

		while (curr != nullptr)
		{
			if (curr->val == val)
			{
				pre->next = curr->next;
				curr = curr->next;
			}
			else
			{
				pre = pre->next;
				curr = curr->next;
			}
		}

		return head;
	}
};