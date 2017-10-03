#pragma once
#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class linkedListCycle {
public:
	bool hasCycle(ListNode *head) {

		ListNode* ptr = head;

		while (ptr) {

			if (nodes.find(ptr) != nodes.end())
				return true;

			nodes.insert(ptr);

			ptr = ptr->next;

		}

		return false;

	};

private:
	unordered_set<ListNode*> nodes;

};