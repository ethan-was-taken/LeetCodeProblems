#pragma once
#include <iostream>
#include <vector>


using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class removeListElements {
public:
	ListNode* removeElements2(ListNode* head, int val) {

		if (head == NULL)
			return head;

		ListNode* list = new ListNode(head->val);
		ListNode* ptr = list;
		vector<ListNode*> nodes;

		while (head != NULL) {
			nodes.push_back(head);
			head = head->next;
		}

		for (int i = 1; i < nodes.size(); i++) {

			if (nodes[i]->val == val)
				continue;

			ptr->next = new ListNode(nodes[i]->val);
			ptr = ptr->next;

		}

		while (list != NULL && list->val == val)
			list = list->next;

		return list;

	};

};