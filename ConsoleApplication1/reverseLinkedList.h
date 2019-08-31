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
	void reorderList(ListNode* firstList) {

		if (!firstList || !firstList->next)
			return;

		ListNode* mid = getMiddleNode(firstList);
		ListNode* secondList = reverseLinkedList(mid);

		reorderList(firstList, secondList);

	};

private:
	ListNode* getMiddleNode(ListNode* head) {

		ListNode* slow = head;
		ListNode* fast = head;

		while (fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
		}

		return slow;

	};

	ListNode* reverseLinkedList(ListNode* head) {

		ListNode* prev = NULL;
		ListNode* curr = head;
		ListNode* next = curr->next;

		while (curr)
			reverse(prev, curr, next);

		return prev;

	};

	void reverse(ListNode* &prev, ListNode* &curr, ListNode* &next) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	};

	void reorderList(ListNode* &firstList, ListNode* secondList) {

		ListNode* firstListNext = firstList->next;
		ListNode* secondListNext = secondList->next;

		while (secondListNext && firstListNext) {
			reorderNodes(firstList, secondList, firstListNext);
			incrementHeadPointers(firstList, firstListNext, secondList, secondListNext);
			incrementNextPointers(firstList, firstListNext, secondList, secondListNext);
		}

	};

	void reorderNodes(ListNode* &firstList, ListNode* &secondList, ListNode* &firstListNext) {
		firstList->next = secondList;
		secondList->next = firstListNext;
	};

	void incrementHeadPointers(ListNode* &firstList, ListNode* &firstNext, ListNode* &secondList, ListNode* &secondNext) {
		firstList = firstNext;
		secondList = secondNext;
	};

	void incrementNextPointers(ListNode* &firstList, ListNode* &firstNext, ListNode* &secondList, ListNode* &secondNext) {
		firstNext = !firstNext ? NULL : firstNext->next;
		secondNext = !secondNext ? NULL : secondNext->next;
	};

};