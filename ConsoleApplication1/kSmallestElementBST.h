#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class kSmallestElementBST {
public:
	int kthSmallest(TreeNode* root, int k) {

		inorderTraversal(root, k, false);

		return hold[k-1];
	};

private:
	void inorderTraversal(TreeNode* root, int k, bool stop) {

		if (root == NULL)
			return;

		if (hold.size() >= k)
			return;

		if (!stop) {
			inorderTraversal(root->left, k, false);
			hold.push_back(root->val);
			inorderTraversal(root->right, k, false);
		}

	}

	vector<int> hold;
};