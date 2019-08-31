#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class ReverseGroup {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {

		ListNode* lptr = head;
		ListNode* rptr = lptr;
		ListNode* prevListTailPtr = NULL;

		int count = 0;

		while (rptr || count == k) {
			
			if (count != k) {
				count++;
				rptr = rptr->next;
				continue;
			}

			ListNode* reversedSubList = reverseSubList(lptr, rptr);

			if (prevListTailPtr)
				prevListTailPtr->next = reversedSubList;
			else
				head = reversedSubList;

			prevListTailPtr = lptr;
			lptr = rptr;

			count = 0;

		}

		if (count != 0 && !prevListTailPtr)
			prevListTailPtr->next = lptr;

		return head;

	};

private:
	inline ListNode* reverseSubList(ListNode* &head, ListNode* &end) {

		ListNode* prev = NULL;
		ListNode* curr = head;
		ListNode* next = curr->next;

		while (curr != end) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}

		return prev;

	};

};