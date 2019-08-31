#pragma once
#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) {
		val = x; 
		left = NULL;
		right = NULL;
	};

	static TreeNode* makeTree(vector<int> nums) {
		TreeNode* gRoot = new TreeNode(nums[0]);
		for (int i = 1; i < nums.size(); i++)
			add(gRoot, nums[i]);			
		return gRoot;
	};

private:
	static void add(TreeNode* gRoot, int key) {

		TreeNode* ptr = getNode(gRoot, key);

		if (ptr->val < key)
			ptr->right = new TreeNode(key);
		else if (ptr->val > key)
			ptr->left = new TreeNode(key);
		else {
			ptr->val = key;
		}

	};

	static TreeNode* getNode(TreeNode* gRoot, int key) {

		TreeNode* ptr = gRoot;
		while (ptr) {
			if (ptr->val == key)
				return ptr;
			if (ptr->val < key && isNextLevelValid(ptr->right))
				ptr = ptr->right;
			else if (ptr->val > key && isNextLevelValid(ptr->left))
				ptr = ptr->left;
			else
				break;
		}

		return ptr;

	}

	static bool isNextLevelValid(TreeNode* curr) {
		return !(!curr || (!curr->left && !curr->right)) || curr;
	}


};