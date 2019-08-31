#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class sortLinkedList {
public:
	static ListNode* sortList(ListNode* head) {

		if (!head || !head->next)
			return head;

		ListNode* prev = NULL;
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast && fast->next) {
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}

		prev->next = NULL;

		ListNode* left = sortList(head);
		ListNode* right = sortList(slow);

		return merge(left, right);

	};

private:
	static inline ListNode* merge(ListNode* &left, ListNode* &right) {

		ListNode* head = new ListNode(INT_MIN);
		ListNode* ptr = head;
		while (left && right) {

			if (left->val <= right->val) {
				ptr->next = new ListNode(left->val);
				left = left->next;
			}
			else {
				ptr->next = new ListNode(right->val);
				right = right->next;
			}

			ptr = ptr->next;

		}

		if (left)
			ptr->next = left;
		else
			ptr->next = right;

		return head->next;

	};

};