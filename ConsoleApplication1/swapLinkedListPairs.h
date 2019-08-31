#pragma once
#include <iostream>
#include "stopper.h"


#define DEBUG 1

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class swapLinkedListPairs {
public:
	static ListNode* swapPairs(ListNode* head) {

		if (head == NULL || head->next == NULL)
			return head;

		ListNode* fakeHead = new ListNode(INT_MIN);
		fakeHead->next = head;

		ListNode* grandparent = fakeHead;
		ListNode* parent = fakeHead->next;
		ListNode* child = fakeHead->next->next;

		int index = 1;
		while (child != NULL /*&& child->next != NULL*/) {

#if DEBUG
			cout << "/*----------------------------------------------" << endl;
			cout << "\t";
			print(fakeHead);
			cout << "\t\t";
			for (int i = 0; i < index; i++)
				cout << "  ";
			cout << "^" << endl;
			cout << "*\tindex:\t" << index << endl;
			cout << "*\tgma:\t" << grandparent->val << endl;
			cout << "*\tparent:\t" << parent->val << endl;
			cout << "*\tchild:\t" << child->val << endl;
			cout << "*----------------------------------------------*/" << endl;
			stopper::stop();
#endif


			if(index % 2 != 0) {

				ListNode* restOfList = child->next;
				grandparent->next = child;
				child->next = parent;
				parent->next = restOfList;

#if DEBUG
				cout << "-----------------------" << endl << "*";
				print(fakeHead);
				cout << "-----------------------" << endl;
				stopper::stop();
#endif

				advanceNodes(grandparent, parent, child);

			}

			advanceNodes(grandparent, parent, child);

#if DEBUG
			print(fakeHead);
			cout << "\t";
			for (int i = 0; i < index; i++)
				cout << "  ";
			cout << "^" << endl;
			stopper::stop();
#endif

			index++;

		}

		return fakeHead->next;

	};

private:
	static void advanceNodes(ListNode* &gma, ListNode* &paren, ListNode* &child) {
		gma = paren;
		paren = child;
		child = (child->next != NULL) ? child->next : NULL;
	};

	static void print(ListNode* ans) {
		ans = ans->next;
		cout << "ans:\t";
		while (ans != NULL) {
			cout << (ans ? to_string(ans->val) : "NULL") << " ";
			ans = ans->next;
		}
		cout << endl;

	};

};
