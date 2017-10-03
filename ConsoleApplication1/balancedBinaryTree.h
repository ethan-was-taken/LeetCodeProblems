#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
	string val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(string x) : val(x), left(NULL), right(NULL) {}
};

class balancedBinaryTree {
public:
	bool isBalanced(TreeNode* root) {

		if (!root)
			return true;

		TreeNode* ptr = root;
		isTreeBalanced = true;
		
		recurse(ptr, 0);

		return isTreeBalanced;

	};
private:
	int recurse(TreeNode* ptr, int depth) {
		
		// No point in searching if we know the tree isnt balanced
		if (!isTreeBalanced)
			return INT_MIN;
		if (!ptr)
			return depth;

		int leftDepth = recurse(ptr->left, depth + 1);
		int rightDepth = recurse(ptr->right, depth + 1);

		int delta = abs(leftDepth - rightDepth);
		if (delta > 1) {
			isTreeBalanced = false;
			return INT_MIN;
		}

		return max(leftDepth, rightDepth);

	};

	bool isTreeBalanced;

};