#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class removeDupsSortedListII {
public:
	ListNode* deleteDuplicates(ListNode* head) {

		// This while loop is for when there are instances like: 
		//		1 -> 1 -> 2 -> 2 -> ...
		while (head != NULL) {

			if (!removeLeadingDups(head))
				break;

		}

		ListNode* curr = head;
		ListNode* prev = curr;

		while (curr != NULL && curr->next != NULL) {

			if (curr->val != curr->next->val) {
				prev = curr;
				curr = curr->next;
				continue;
			}

			while (curr->next != NULL && curr->val == curr->next->val)
				curr = curr->next;

			prev->next = curr->next;
			curr = curr->next;

		}

		return head;

	};
private:
	// Returns true if there were leading duplicates, otherwise false
	inline bool removeLeadingDups(ListNode* &head) {

		ListNode* currPtr = head;
		bool hasLeadingDups = false;

		while (currPtr->next != NULL && currPtr->val == currPtr->next->val) {

			currPtr = currPtr->next;
			head = currPtr->next;
			hasLeadingDups = true;

		}

		return hasLeadingDups;

	};

};