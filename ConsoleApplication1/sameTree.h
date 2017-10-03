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

class sameTree {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		
		dfs(p, pFlat);
		dfs(q, qFlat);

		if (pFlat.size() != qFlat.size()) {
			return false;
		}

		for (int i = 0; i < pFlat.size(); i++) {
			if (pFlat[i]->val != qFlat[i]->val) {
				return false;
			}
		}

		return true;

	};

private:
	inline void dfs(TreeNode* curr, vector<TreeNode*> &path) {

		if (!curr) {
			path.push_back(new TreeNode(INT_MIN));
			return;
		}

		path.push_back(curr);

		dfs(curr->left, path);
		dfs(curr->right, path);

	};

	void print() {
		
		cout << "p: ";
		for (TreeNode* i : pFlat) {
			cout << i->val << "\t";
		}
		cout << endl;

		cout << "q: ";
		for (TreeNode* i : qFlat) {
			cout << i->val << "\t";
		}
		cout << endl;

	}

	vector<TreeNode*> pFlat;
	vector<TreeNode*> qFlat;

};