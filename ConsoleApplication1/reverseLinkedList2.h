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

class reverseLinkedList2 {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {

		// Handle some edge cases
		if (!head || !head->next || m == n)
			return head;

		ListNode* begPtr = head;

		// Get to the node before m
		for (int i = 1; i < m - 1; i++)
			begPtr = begPtr->next;

		if (m == 1) {
			recurse(m, n, begPtr);
			begPtr->next->next = begPtr;
			begPtr->next = endsNextNode;
			head = endNode;
		}
		else {
			recurse(m, n, begPtr->next);
			// Set the mth node to endsNextNode and the m-1th node to the nth node
			begPtr->next->next = endsNextNode;
			begPtr->next = endNode;
		}

		return head;
	};
private:
	void recurse(int counter, int n, ListNode* currPtr) {

		if (counter == n) {
			endsNextNode = currPtr->next;
			endNode = currPtr;
			return;
		}

		ListNode* prevPtr = currPtr;
		currPtr = currPtr->next;

		if (currPtr) {
			recurse(counter + 1, n, currPtr);
			currPtr->next = prevPtr;
		}
		else {
			endsNextNode = NULL;
			endNode = currPtr;
		}

	};

	ListNode* endsNextNode;
	ListNode* endNode;

};