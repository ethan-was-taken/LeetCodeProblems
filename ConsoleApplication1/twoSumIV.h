#pragma once
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

#include "printer.h"
#include "stopper.h"

using namespace std;

class twoSumIV {
public:
	static bool findTarget(TreeNode* root, int target) {
		
		unordered_set<int> nums;
		inorderTraversal(root, nums);

		printer::print(nums);
		stopper::stop();

		for (auto curr : nums) {
			int delta = target - curr;
			if (nums.find(delta) != nums.end() && *nums.find(delta) != curr)
				return true;
		}

		return false;

	};

private:
	static inline void inorderTraversal(TreeNode* curr, unordered_set<int> &nums) {
		
		if (!curr)
			return;

		inorderTraversal(curr->left, nums);
		nums.emplace(curr->val);
		inorderTraversal(curr->right, nums);

	};
};