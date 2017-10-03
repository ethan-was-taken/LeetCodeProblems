#pragma once
#include <iostream>
#include <string>


using namespace std;

struct ListNode {
	int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class linkedListsIntersection {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		/*
		1.	Figure out which is the longer of the two lists
		2.	Advance the longer list till its the same length as the smaller list
		3.	Recursively go through the two linked lists until you get to the ends of each list
		4.	Once you've reached the end: Check if the ends are the same
				If they arent -> return NULL
				Otherwise -> return
		5.	Continue checking the ends until they are no longer equal
				The node checked before that is the intersection
		*/
		
		if (!headA || !headB)
			return NULL;

		ListNode* aptr = headA;
		ListNode* bptr = headB;
		int aSize = getListSize(aptr);
		int bSize = getListSize(bptr);

		cout << "asize: " << aSize << endl;
		cout << "bSize: " << bSize << endl;

		// Reset ptrs since they'll be pointing to the last nodes
		aptr = headA;
		bptr = headB;

		if (aSize > bSize)
			aptr = advancePtr(aptr, (aSize - bSize));
		else
			bptr = advancePtr(bptr, (bSize - aSize));
		
		cout << "aptr pointing to: " << aptr->val << endl;
		cout << "bptr pointing to: " << bptr->val << endl;

		while (aptr && bptr) {

			/*if (aptr->val == bptr->val)
				return aptr;*/
			if (aptr == bptr)
				return aptr;
			
			aptr = aptr->next;
			bptr = bptr->next;

		}

		return NULL;

	};

private:
	int getListSize(ListNode* ptr) {

		int count = 0;

		while (ptr) {
			count++;
			cout << "ptr.val: " << ptr->val << endl;
			ptr = ptr->next;
		}

		cout << endl;

		return count;

	};

	ListNode* advancePtr(ListNode* ptr, int amount) {
		for (int i = 0; i < amount; i++)
			ptr = ptr->next;
		return ptr;
	};
	

};