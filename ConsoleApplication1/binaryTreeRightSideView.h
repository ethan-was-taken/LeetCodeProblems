#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <set>


using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class binaryTreeRightSideView {
public:
	vector<int> rightSideView(TreeNode* root) {

		vector<vector<int>> tree;
		vector<int> rightSide;
		
		dfs(root, tree, 0);
		
		getValues(tree, rightSide);

		return rightSide;

	};

private:
	inline void dfs(TreeNode* curr, vector<vector<int>> &tree, int level) {

		if (curr == NULL)
			return;

		if (tree.size() - 1 < level || tree.empty()) {
			tree.push_back(vector<int>());
		}

		tree[level].push_back(curr->val);

		dfs(curr->left, tree, level + 1);
		dfs(curr->right, tree, level + 1);

	};

	inline void getValues(vector<vector<int>> &tree, vector<int> &rightSide) {

		for (int i = 0; i < tree.size(); i++)
			rightSide.push_back(tree[i].back());
		
	};

	void print(vector<vector<int>> &ans) {
		for (int i = 0; i < ans.size(); i++) {

			for (int j = 0; j < ans[i].size(); j++)
				cout << ans[i][j] << " ";

			cout << endl;

		}

		int stop;
		cout << "\t\t\t\t\t";
		cin >> stop;

	};

};