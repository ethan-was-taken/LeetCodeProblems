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

class subtreeOfAnotherTree {
public:
	bool isSubtree(TreeNode* s, TreeNode* t) {

		dfs(s, sInOrder);
		dfs(t, tInOrder);

		for (int i = 0; i < sInOrder.size(); i++) {

			auto currS = sInOrder[i];

			if (currS->val == tInOrder[0]->val && check(i) == -1) {
				return true;
			}

		}

		return false;

	};


private:
	inline void dfs(TreeNode* curr, vector<TreeNode*> &inOrder) {


		if (!curr) {
			inOrder.push_back(new TreeNode(INT_MAX));
			return;
		}

		inOrder.push_back(curr);

		dfs(curr->left, inOrder);
		dfs(curr->right, inOrder);

	};

	inline int check(int start) {

		int j = 0;
		for (int i = start; i < sInOrder.size() && j < tInOrder.size(); i++) {

			auto currS = sInOrder[i];
			auto currT = tInOrder[j++];

			if (currS->val != currT->val)
				return i;

		}

		return -1;

	}

	vector<TreeNode*> sInOrder;
	vector<TreeNode*> tInOrder;

};