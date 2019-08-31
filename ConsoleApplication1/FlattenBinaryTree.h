#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class FlattenBinaryTree {
public:
	void flatten(TreeNode* root) {
		preorderFlatten(root, 0);
	};

private:
	pair<TreeNode*, int> rightMostPtr;

	void preorderFlatten(TreeNode* node, int lvl) {
		
		if (!node)
			return;

		TreeNode lptr = *node->left;
		TreeNode rptr = *node->right;

		if (rightMostPtr.second <= lvl)
			rightMostPtr.first = node;

		node->left = nullptr;
		node->right = &lptr;
		preorderFlatten(node->right, lvl + 1);

		rightMostPtr.first->right = &rptr;
		rightMostPtr.first = rightMostPtr.first->right;
		preorderFlatten(rightMostPtr.first->right->left, rightMostPtr.second + 1);

	};

};