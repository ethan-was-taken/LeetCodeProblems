#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class maximumDepth{
public:
	int maxDepth(TreeNode* root) {

		dfs(root, 0);

		return max;

	};

private:
	void dfs(TreeNode* curr, int depth) {

		if (curr == NULL) {
			max = (depth > max) ? depth : max;
			return;
		}

		dfs(curr->left, depth + 1);
		dfs(curr->right, depth + 1);

	};

	int max;
};