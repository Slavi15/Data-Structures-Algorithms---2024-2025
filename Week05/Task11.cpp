/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
	int getLength(ListNode* head)
	{
		int res = 0;

		while (head != nullptr)
		{
			res++;
			head = head->next;
		}

		return res;
	}

	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
	{
		int lenA = getLength(headA);
		int lenB = getLength(headB);

		while (lenA < lenB)
		{
			lenA++;
			headB = headB->next;
		}

		while (lenB < lenA)
		{
			lenB++;
			headA = headA->next;
		}

		while (headA != nullptr && headB != nullptr)
		{
			if (headA == headB) return headA;

			headA = headA->next;
			headB = headB->next;
		}

		return nullptr;
	}
};