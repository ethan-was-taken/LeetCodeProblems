#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "treeNode.h"

using namespace std;

class validateBST {
public:
	static bool isValidBST(TreeNode* root) {
		
		vector<int> inorder;
		inorderTraversal(root, inorder);

		for (int i = 1; i < inorder.size(); i++) {
			if (inorder[i] <= inorder[i - 1])
				return false;
		}

		return true;

	};

private:
	inline static void inorderTraversal(TreeNode* curr, vector<int> &path) {

		if (!curr)
			return;
		
		inorderTraversal(curr, path);
		path.push_back(curr->val);
		inorderTraversal(curr, path);

	};
};