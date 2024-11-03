#include <stack>

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
	bool isPalindrome(ListNode* head)
	{
		std::stack<int> stack;
		ListNode* curr = head;

		while (curr != nullptr)
		{
			stack.push(curr->val);
			curr = curr->next;
		}

		while (head != nullptr)
		{
			if (head->val != stack.top()) return false;

			stack.pop();
			head = head->next;
		}

		return true;
	}
};