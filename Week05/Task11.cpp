struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode* detectCycle(ListNode* head)
	{
		std::unordered_map<ListNode*, bool> uMap;

		while (head != nullptr)
		{
			if (uMap.find(head) != uMap.end())
			{
				return head;
			}

			uMap[head] = true;
			head = head->next;
		}

		return nullptr;
	}
};

class Solution
{
public:
	ListNode* detectCycle(ListNode* head)
	{
		ListNode* slow = head;
		ListNode* fast = head;

		while (fast != nullptr && fast->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;

			if (slow == fast)
			{
				while (fast != head) // in order for the head and fast pointer to meet at the cycle node
				{
					head = head->next;
					fast = fast->next;
				}

				return head;
			}
		}

		return nullptr;
	}
};