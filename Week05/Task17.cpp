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
	ListNode* rotateRight(ListNode* head, int k)
	{
		if (head == nullptr || head->next == nullptr || k == 0) return head;

		int length = 1;
		ListNode* temp = head;

		while (temp->next != nullptr)
		{
			length++;
			temp = temp->next;
		}

		temp->next = head;

		k %= length;
		int upto = length - k;

		temp = head;
		for (int i = 1; i < upto; i++) temp = temp->next;

		ListNode* newHead = temp->next;

		temp->next = nullptr;

		return newHead;
	}
};

class Solution
{
public:
	ListNode* rotateRight(ListNode* head, int k)
	{
		if (head == nullptr || head->next == nullptr || k == 0) return head;

		std::vector<ListNode*> arr;

		ListNode* temp = head;

		while (temp != nullptr)
		{
			arr.push_back(temp);
			temp = temp->next;
		}

		k %= arr.size();
		int l = 0, r = arr.size() - k;
		int count = 0;

		ListNode* curr = nullptr, * tempHead = nullptr;

		while (count++ < arr.size())
		{
			if (k-- > 0)
			{
				if (!tempHead)
				{
					tempHead = arr[r++];
					curr = tempHead;
				}
				else
				{
					curr->next = arr[r++];
					curr = curr->next;
				}
			}
			else
			{
				if (!tempHead)
				{
					tempHead = arr[l++];
					curr = tempHead;
				}
				else
				{
					curr->next = arr[l++];
					curr = curr->next;
				}
			}
		}

		curr->next = nullptr;
		return tempHead;
	}
};