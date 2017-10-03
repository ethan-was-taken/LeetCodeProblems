#pragma once
#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class linkedListCycleII {
public:
	ListNode* detectCycle(ListNode *head) {

		ListNode* ptr = head;

		while (ptr) {

			if (nodes.find(ptr) != nodes.end())
				return ptr;

			nodes.insert(ptr);

			ptr = ptr->next;

		}

		return NULL;

	};

private:
	unordered_set<ListNode*> nodes;

};