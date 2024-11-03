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

class Solution {
public:
	void reorderList(ListNode* head) {
		std::vector<ListNode*> arr;

		ListNode* temp = head;

		while (temp != nullptr) {
			arr.push_back(temp);
			temp = temp->next;
		}

		int l = 1, r = arr.size() - 1;

		ListNode* curr = head;

		while (l <= r) {
			if (l == r) {
				curr->next = arr[l];
				curr = curr->next;
				break;
			}

			curr->next = arr[r--];
			curr = curr->next;

			curr->next = arr[l++];
			curr = curr->next;
		}

		curr->next = nullptr;
	}
};