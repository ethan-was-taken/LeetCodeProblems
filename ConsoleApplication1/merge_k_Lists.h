#pragma once
#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//Solution
class merge_k_Lists {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {

		ListNode* sorted;

		if (lists.size() == 0)
			return sorted;

		sorted = lists[0]; /*mergeTwoLists(lists[0], lists[1]);*/

		for (int i = 1; i < lists.size(); i++) {
			cout << i << endl;
			sorted = mergeTwoLists(sorted, lists[i]);
		}

		cout << "returned " << endl;
		return sorted;

	};
private:
	ListNode* mergeTwoLists(ListNode* listOnePtr, ListNode* listTwoPtr) {

		cout << "------mergeTwoLists------ " << endl;

		ListNode sorted(-1);
		ListNode* sortedPtr = &sorted;

		cout << "1" << endl;

		if (listOnePtr == nullptr)
			return listTwoPtr;
		else if (listTwoPtr == nullptr)
			return listOnePtr;

		while (listTwoPtr && listOnePtr) {

			cout << "2" << endl;

			if (listOnePtr->val <= listTwoPtr->val) {
				cout << "3" << endl;
				sortedPtr->next = listOnePtr;
				listOnePtr = listOnePtr->next;
			}
			else if (listTwoPtr->val < listOnePtr->val) {
				cout << "4" << endl;
				sortedPtr->next = listTwoPtr;
				listTwoPtr = listTwoPtr->next;
			}
			cout << "5" << endl;
			sortedPtr = sortedPtr->next;
		}

		sortedPtr->next = listOnePtr ? listOnePtr : listTwoPtr;
		cout << "------mrgTwoLsts------ " << endl;
		return sorted.next;
	};
};