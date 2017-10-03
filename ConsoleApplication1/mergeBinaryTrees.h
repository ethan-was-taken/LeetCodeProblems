#pragma once
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class mergeBinaryTrees {
public:
	TreeNode* mergeTrees(TreeNode* first, TreeNode* second) {

		if (!first)
			return second;
		if (!second)
			return first;


		first->val += second->val;

		first->left = mergeTrees(first->left, second->left);
		first->right = mergeTrees(first->right, second->right);

		return first;

	};

};