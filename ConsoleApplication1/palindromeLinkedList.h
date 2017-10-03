#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class palindromeLinkedList {
public:
	bool isPalindrome(ListNode* head) {
		
		if (head == NULL)
			return true;

		//ListNode* prev = head;
		ListNode* slowPtr = head;
		ListNode* fastPtr = head;

		while (fastPtr->next != NULL && fastPtr->next->next != NULL) {
			
			slowPtr = slowPtr->next;
			fastPtr = fastPtr->next->next;

		}

		slowPtr->next = reverse(slowPtr->next);
		slowPtr = slowPtr->next;

		while (slowPtr != NULL) {
		
			if (head->val != slowPtr->val)
				return false;

			head = head->next;
			slowPtr = slowPtr->next;

		}

		return true;

	};

private:
	void print(ListNode* ptr) {

		cout << "---------PRINT---------" << endl;

		while (ptr != NULL) {
			cout << ptr->val << "\t";
			ptr = ptr->next;
		}
		cout << endl;

		int stop;
		cout << "\t\t\t\t\t";
		cin >> stop;

	}

	void print(string s, int ptr) {

		cout << s << ":\t" << ptr << endl;

		int stop;
		cout << "\t\t\t\t\t";
		cin >> stop;

	}

	//https://leetcode.com/problems/palindrome-linked-list/discuss/
	inline ListNode* reverse(ListNode* ptr) { 

		ListNode* prevNode = NULL;
		ListNode* nextNode = NULL;

		while (ptr != NULL) {
			
			nextNode = ptr->next;
			ptr->next = prevNode;
			prevNode = ptr;
			
			ptr = nextNode;
			
		}

		return prevNode;

	};

};