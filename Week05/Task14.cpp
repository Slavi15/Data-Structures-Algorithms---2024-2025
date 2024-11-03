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
	ListNode* partition(ListNode* head, int x)
	{
		if (!head || !head->next) return nullptr;

		ListNode* lhead = nullptr, * rhead = nullptr;
		ListNode* left = nullptr, * right = nullptr;

		while (head != nullptr)
		{
			if (head->val < x)
			{
				if (!lhead)
				{
					left = head;
					lhead = left;
				}
				else
				{
					left->next = head;
					left = left->next;
				}
			}
			else
			{
				if (!rhead)
				{
					right = head;
					rhead = right;
				}
				else
				{
					right->next = head;
					right = right->next;
				}
			}

			head = head->next;
		}

		if (right != nullptr) right->next = nullptr;
		if (left != nullptr) left->next = rhead;

		return lhead ? lhead : rhead;
	}
};