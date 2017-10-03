#pragma once
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class commonAncestor {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

		if (p == NULL || q == NULL || root == NULL)
			return nullptr;

		//vector<TreeNode*> pPath;
		getPath(root, p, pPath);
		pPath = longest;

		//RESET
		longest.clear();

		//vector<TreeNode*> qPath;
		getPath(root, q, qPath);
		qPath = longest;

		return getCommon(pPath, qPath);
	}

private:
	// A DFS that finds the path to get from the root node to the given treenode
	inline void getPath(TreeNode* curr, TreeNode* target, vector<TreeNode*> &path) {
		//-------------------------
		cout << "longest path: ";
		for (TreeNode* i : longest)
			cout << i->val << " ";
		cout << endl;
		//-------------------------

		//BASS case
		if (curr == NULL || &curr == nullptr) {

			if (isEqual(path.back(), target) && path.size() >= longest.size())
				longest = path;

			return;
		}
		else if (isEqual(curr, target) && path.size() >= longest.size()) {
			path.push_back(curr);
			longest = path;
		}

		path.push_back(curr);

		getPath(curr->left, target, path);
		getPath(curr->right, target, path);

		if (!path.empty())
			path.pop_back();

		return;
	}

	inline TreeNode* getCommon(vector<TreeNode*> pPath, vector<TreeNode*> qPath) {

		if (pPath == qPath)
			return qPath[0];

		for (int i = pPath.size() - 1; i >= 0; i--) {
			for (int j = qPath.size() - 1; j >= 0; j--) {
				if (pPath[i]->val == qPath[j]->val)
					return pPath[i];
			}
		}

		return nullptr;
	};

	inline bool isEqual(TreeNode* curr, TreeNode* target) {

		bool temp = curr->val == target->val;
		return temp;
	};

	//-----
	vector<TreeNode*> longest;
	vector<TreeNode*> pPath;
	vector<TreeNode*> qPath;

};