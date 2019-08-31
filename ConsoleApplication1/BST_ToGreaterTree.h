#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <stack>

#include "TreeNode.h"

#include "printer.h"
#include "stopper.h"

using namespace std;

class BST_ToGreaterTree {
public:
	static TreeNode* convertBST(TreeNode* root) {
		convertBST(root, 0);
		return root;
	};

private:
	/*
	A backwards inorder traversal (i.e. right-root-left) that converts a binary search
	  tree into a greater tree
	*/
	static inline int convertBST(TreeNode* curr, int currTotal) {

		if (!curr)
			return currTotal;

		int rightSum = convertBST(curr->right, currTotal);
		curr->val += rightSum;
		return convertBST(curr->left, curr->val);

	};
	
};