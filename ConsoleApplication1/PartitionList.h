#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {};
};

class PartitionList {
public:
	ListNode* partition(ListNode* head, int x) {

		if (!head)
			return head;

		setup(head);
		setPivot(head, x);

		if (!pivot)
			return head;

		ListNode* trailer = beforePivot;
		for (ListNode* curr = pivot; curr && curr->next; curr = curr->next) {

			if (curr->next->val < x) {
				beforePivot->next = curr->next;
				beforePivot = beforePivot->next;
				curr->next = curr->next->next;
				beforePivot->next = pivot;
			}

			trailer = curr;

		}

		/*
		At this point trailer->next is the last element in the list:
		2	5	4	3	1
		^
		*/

		if (trailer->next && trailer->next->val < x) {
			beforePivot->next = trailer->next;
			beforePivot = beforePivot->next;
			trailer->next = NULL;
			beforePivot->next = pivot;
		}

		return result->next;


	};

private:
	ListNode* result;
	ListNode* beforePivot;
	ListNode* pivot;

	inline void setup(ListNode* &head) {
		beforePivot = new ListNode(INT_MIN);
		beforePivot->next = head;
		result = beforePivot;
	};

	void setPivot(ListNode* head, int x) {

		pivot = NULL;

		ListNode* curr = head;
		while (curr) {

			if (curr->val >= x) {
				pivot = curr;
				return;
			}

			beforePivot = curr;
			curr = curr->next;

		}

	};

};