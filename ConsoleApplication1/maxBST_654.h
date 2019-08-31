#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

#include "TreeNode.h"
#include "printer.h"
#include "stopper.h"

using namespace std;


class maxBST_654 {
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		
		this->nums = nums;

		int rootIndex = findMaxIndex(0, nums.size());
		root = new TreeNode(nums[rootIndex]);
		
		constructMaximumBinaryTree(root, true, 0, rootIndex);
		constructMaximumBinaryTree(root, false, rootIndex + 1, nums.size());
		
		cout << "================================" << endl;
		printer::postorder(root);
		cout << "================================" << endl;

		return root;

	};

private:
	void constructMaximumBinaryTree(TreeNode* curr, bool goLeft, int start, int end) {

		int maxIndex = findMaxIndex(start, end);
		if (maxIndex == -1)
			return;

		add(curr, nums[maxIndex], goLeft);

		// setup values for next round
		TreeNode* next = (goLeft) ? curr->left : curr->right;
		goLeft = (maxIndex <= start) ? false : true;
		start = (goLeft) ? start : start + 1 ;
		end = (goLeft) ? maxIndex : end;

		statusCheck(next, goLeft, start, end);

		constructMaximumBinaryTree(next, goLeft, start, end);

	};

	void add(TreeNode* curr, int val, bool addToLeft) {

		if (addToLeft) {
			curr->left = new TreeNode(val);
		}
		else {
			curr->right = new TreeNode(val);
		}

	};

	int findMaxIndex(int start, int end) {

		if (start >= end)
			return -1;

		int maxi = INT_MIN;
		int index = 0;
		for (int i = start; i < end; i++) {
			if (nums[i] > maxi) {
				maxi = nums[i];
				index = i;
			}
		}

		return index;

	};

	void statusCheck(TreeNode* next, bool goLeft, int start, int end) {

		cout << "--------------------------------" << endl;
		cout << "next:\t" << next->val << endl;
		cout << "goLeft:\t";
		printer::print(goLeft);
		cout << "start:\t" << start << endl;
		cout << "end:\t" << end << endl;
		cout << "--------------------------------" << endl;
		for (int i = start; i < end; i++)
			cout << nums[i] << " ";
		cout << endl;
		cout << "--------------------------------" << endl;

		printer::postorder(root);
		
		stopper::stop();

	}

	TreeNode* root;
	vector<int> nums;

};