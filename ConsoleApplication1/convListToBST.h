#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class convListToBST {
public:
	TreeNode* sortedListToBST(ListNode* head) {

		if (!head)
			return NULL;

		addToVector(head);

		/*
		if (list.size() == 2) {
			TreeNode* head2 = new TreeNode(list[1]);
			TreeNode* headPtr = head2;
			headPtr->left = new TreeNode(list[0]);
			return head2;
		}
		*/

		root = modifiedBinarySearch(0, nums.size() - 1);

		return root;
	};

private:
	// Had a little help looking at the solution -> ans was similar but different
	TreeNode* modifiedBinarySearch(int lptr, int rptr) {

		int mid = (rptr - lptr) / 2 + lptr;

		if (rptr < lptr)
			return NULL;
		
		TreeNode* curr = new TreeNode(NULL);

		// Go down left			
		curr->left = new TreeNode(NULL);
		TreeNode* left = modifiedBinarySearch(lptr, mid - 1);
		curr->left = left;
		
		// Root
		curr->val = nums[mid];

		// Go down right
		curr->right = new TreeNode(NULL);
		TreeNode* right = modifiedBinarySearch(mid + 1, rptr);
		curr->right = right;

		return curr;

	};

	void addToVector(ListNode* head) {

		while (head) {
			nums.push_back(head->val);
			head = head->next;
		}

	}

	// Global var so that nums doesnt always have to be put on the stack
	vector<int> nums;
	TreeNode* root;
};