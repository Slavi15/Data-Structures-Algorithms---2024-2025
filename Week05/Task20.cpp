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
	int gcd(int a, int b)
	{
		return b == 0 ? a : gcd(b, a % b);
	}

	ListNode* insertGreatestCommonDivisors(ListNode* head)
	{
		ListNode* pre = head, * curr = head->next;

		while (curr != nullptr)
		{
			int gcdValue = gcd(pre->val, curr->val);

			ListNode* newNode = new ListNode(gcdValue);

			pre->next = newNode;
			newNode->next = curr;

			pre = curr;
			curr = curr->next;
		}

		return head;
	}
};