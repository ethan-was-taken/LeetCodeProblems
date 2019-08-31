#pragma once
#include <iostream>
#include <iomanip>
#include <vector>

#include "printer.h"
#include "stopper.h"
#include "TreeNode.h"

using namespace std;


class invertBinaryTree {
public:
	static TreeNode* invertTree(TreeNode* root) {
		if (!root)
			return NULL;
		dfs(root);
		return root;
	};

private:
	static void dfs(TreeNode* curr) {

		if (!curr)
			return;

		if (!isLeaf(curr))
			swapNodes(curr);

		dfs(curr->left);
		dfs(curr->right);

	};

	static bool isLeaf(TreeNode* curr) {
		return !curr->left && !curr->right;
	};

	static void swapNodes(TreeNode* &curr) {
		TreeNode* temp = curr->left;
		curr->left = curr->right;
		curr->right = temp;
	};

};
