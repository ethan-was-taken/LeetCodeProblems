#pragma once
#include <iostream>
#include <unordered_set>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;

class removeDuplicates_83 {
public:
	ListNode* deleteDuplicates(ListNode* head) {

		/*
		1.	lptr = head
			rptr = head.next

		2.	while lptr != null && rptr != null
				// This could cause a memory leak since the dup. nodes are not being 
				//	deleted and theres no garbage collection
				if lptr.val == rptr.val
					rptr = rptr.next
					continue
				
				lptr.next = rptr
				lptr = rptr
				rptr = rptr.next

		3.	lptr.next = rptr
		*/

		if (!head)
			return head;

		ListNode* lptr = head;
		ListNode* rptr = head->next;

		while (lptr != NULL && rptr != NULL) {

			if (lptr->val == rptr->val) {
				rptr = rptr->next;
				continue;
			}

			cout << "lptr:\t" << lptr->val << endl;
			cout << "rptr:\t" << rptr->val << endl;

			lptr->next = rptr;
			lptr = lptr->next;
			rptr = rptr->next;

			print(head);

		}

		lptr->next = rptr;

		print(head);

		return head;

	};

	void print(ListNode* ans) {

		cout << endl;
		while (ans) {
			cout << ans->val << "\t";
			ans = ans->next;
		}
		cout << endl;
		cout << "------------------------------------" << endl;
		stopper();

	}
	void stopper() {
		int stop;
		cout << "\t\t\t\t\t";
		cin >> stop;
	};

};