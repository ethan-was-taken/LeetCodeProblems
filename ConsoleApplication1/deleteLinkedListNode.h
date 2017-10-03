#pragma once
#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class deleteLinkedListNode {
public:
	void deleteNode(ListNode* node) {

		ListNode* ptr = node;
		while (true) {
			
			ptr->val = ptr->next->val;
			
			if (ptr->next->next == NULL) {
				ptr->next = NULL;
				break;
			}

			ptr = ptr->next;

		}

	};

};