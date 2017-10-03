#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class reverseLinkedList {
public:
	ListNode* reverseList(ListNode* head) {

		// Handle some edge cases
		if (!head || !head->next)
			return head;

		ListNode* begPtr = head;
		vector<ListNode*> hold;
		while (begPtr) {
			hold.push_back(begPtr);
			begPtr = begPtr->next;
		}

		for (int i = hold.size() - 1; i >= 1; i--) {
			hold[i]->next = hold[i - 1];
		}
		hold[0]->next = NULL;
		head = hold.back();

		return head;

	};
};