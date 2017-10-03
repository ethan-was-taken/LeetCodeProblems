#pragma once
#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class oddEvenLinkedList {
public:
	ListNode* oddEvenList(ListNode* head) {

		if (head == NULL)
			return head;

		ListNode* ptr = head;

		vector<ListNode*> nodes;
		while (ptr != NULL) {
			nodes.push_back(ptr);
			ptr = ptr->next;
		}

		ptr = head;
		addToList(nodes, ptr, 2);
		addToList(nodes, ptr, 1);
		ptr->next = NULL;

		return head;

	};

private:
	inline void addToList(vector<ListNode*> &nodes, ListNode* &ptr, int start) {

		for (int i = start; i < nodes.size(); i += 2) {
			ptr->next = nodes[i];
			ptr = ptr->next;
		}

	};

	ListNode* betterSolution(ListNode* head) {

		if (head == NULL)
			return head;

		ListNode* odd = head;
		ListNode* even = head->next;
		ListNode* evenHead = even;

		while (even != NULL && even->next != NULL) {

			odd->next = even->next;
			odd = odd->next;

			even->next = odd->next;
			even = even->next;

		}

		odd->next = evenHead;

		return head;

	};

};