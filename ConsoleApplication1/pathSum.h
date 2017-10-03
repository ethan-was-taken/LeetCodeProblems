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

class pathSum {
public:
	bool hasPathSum(TreeNode* root, int sum) {

		if(root == NULL)
			return false;
		if (isLeaf(root))
			return root->val == sum;

		return dfs(root, 0, sum);

	};

private:
	bool dfs(TreeNode* curr, int currSum, int target) {
		
		if (curr == NULL)
			return false;

		currSum += curr->val;
		cout << "currSum:\t" << currSum << endl;

		if (isLeaf(curr) && currSum == target) {
			cout << "TRUE!!!" << endl;
			return true;
		}
		if (isLeaf(curr))
			return false;


		bool left = dfs(curr->left, currSum, target);
		bool right = dfs(curr->right, currSum, target);
		
		return left || right;

	};

	inline bool isLeaf(TreeNode* curr) {
		return curr->left == NULL && curr->right == NULL;
	};

};