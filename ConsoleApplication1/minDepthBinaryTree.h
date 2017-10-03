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

class minDepthBinaryTree {
public:
	int minDepth(TreeNode* root) {

		if (root == NULL)
			return 0;

		int min1 = dfs(root->left, 1);;
		int min2 = dfs(root->right, 1);
		int ans = min(min1, min2);

		return (ans == INT_MAX) ? 1 : ans;

	};

private:
	inline int dfs(TreeNode* currNode, int pathLength) {

		if (currNode == NULL)
			return INT_MAX;
		
		if (currNode->left == NULL && currNode->right == NULL) 
			return pathLength + 1;
	
		int minPathLeft = dfs(currNode->left, pathLength + 1);
		int minPathRight = dfs(currNode->right, pathLength + 1);

		return min(minPathLeft, minPathRight);

	};

};