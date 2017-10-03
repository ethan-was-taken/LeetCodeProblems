#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class removeNthNode {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {

		/*ListNode* slowPtr = head;
		ListNode* fastPtr = head;
		
		int count = 0;
		while (!fastPtr->next) {

			slowPtr = slowPtr->next;
			if(!fastPtr->next->next)
				fastPtr = fastPtr->next->next;

		}*/

		ListNode* ptr = head;

		vector<ListNode*> nodes;
		while (ptr != NULL) {
			nodes.push_back(ptr);
			ptr = ptr->next;
		}

		cout << "nodes:\t";
		for (auto i : nodes) {
			cout << i->val << "\t";
		}
		cout << endl;

		int indexToDelete = nodes.size() - n;

		cout << "index\t" << indexToDelete << endl;

		if (indexToDelete + 1 >= nodes.size())
			nodes[indexToDelete - 1]->next = NULL;
		else if()
			nodes[indexToDelete - 1]->next = nodes[indexToDelete + 1];


		// Dont want a memory leak!
		delete nodes[indexToDelete];


		return head;

	};
};