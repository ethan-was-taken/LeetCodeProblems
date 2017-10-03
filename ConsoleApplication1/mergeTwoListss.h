#pragma once
#include <iostream>


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;

//Solution
class mergeTwoListss {
public:
	ListNode* mergeTwoLists(ListNode* listOnePtr, ListNode* listTwoPtr) {

		ListNode sorted(-1);
		ListNode* sortedPtr = &sorted;

		while (listTwoPtr && listOnePtr) {

			if (listOnePtr->val <= listTwoPtr->val) {
				sortedPtr->next = listOnePtr;
				listOnePtr = listOnePtr->next;
			}
			else if (listTwoPtr->val < listOnePtr->val) {
				sortedPtr->next = listTwoPtr;
				listTwoPtr = listTwoPtr->next;
			}

			sortedPtr = sortedPtr->next;
		}

		sortedPtr->next = listOnePtr ? listOnePtr : listTwoPtr;
		return sorted.next;
	};
};