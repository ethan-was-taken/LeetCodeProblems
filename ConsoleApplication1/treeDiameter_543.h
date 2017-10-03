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

class treeDiameter_543 {
public:
	int diameterOfBinaryTree(TreeNode* root) {

		if (!root)
			return 0;

		int leftLen = dfs(root->left, 1);
		int rightLen = dfs(root->right, 1);
		int length = leftLen + rightLen;

		return max(length, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
		
	};

private:
	inline int dfs(TreeNode* curr, int currLength) {
		
		if (!curr)
			return currLength - 1;

		int leftLen = dfs(curr->left, currLength + 1);
		int rightLen = dfs(curr->right, currLength + 1);

		return max(leftLen, rightLen);

	};

};