#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "printer.h"

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class removeNthNode {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {

		// make sure its valid
		if (n == 0 || !head)
			return head;

		setPointers(head);
		setupPointer(n);

		if (!ptr)
			return removeHead(head);

		setPointersToCorrectPos();
		removeTheNthNode();
		return head;

	};

private:
	ListNode* ptr;
	ListNode* trailingPtr;

	void setPointers(ListNode* head) {
		ptr = head;
		trailingPtr = head;
	};

	void setupPointer(int n) {
		for (int i = 0; i < n + 1 && ptr; i++)
			ptr = ptr->next;
	};

	ListNode* removeHead(ListNode* head) {
		ListNode* temp = head->next;
		delete(head);
		head = temp;
		return head;
	};

	void setPointersToCorrectPos() {
		while (ptr->next) {
			ptr = ptr->next;
			trailingPtr = trailingPtr->next;
		}
	};

	void removeTheNthNode() {
		ListNode* temp = trailingPtr->next->next;
		delete(trailingPtr->next);
		trailingPtr->next = temp;
	};

};