#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "printer.h"

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class lowestCommonAncestorBST {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

		if (root == NULL)
			return NULL;

		vector<TreeNode*> pPath; 
		vector<TreeNode*> qPath;
		getPath(root, p, pPath);		
		getPath(root, q, qPath);

		int i = 1;
		for (; i < pPath.size() && i < qPath.size(); i++) {
			if (pPath[i] != qPath[i]) 
				break;
		}

		return (pPath.size() != 0 && qPath.size() != 0) ? pPath[i - 1] : NULL;

	};

private:
	inline void getPath(TreeNode* root, TreeNode* target, vector<TreeNode*> &path) {

		// This means that the value isnt in the tree so clera path
		if (root == NULL) {
			path.clear();
			return;
		}

		path.push_back(root);

		if (root->val == target->val)
			return;
					
		if(root->val < target->val)
			getPath(root->right, target, path);
		else
			getPath(root->left, target, path);

	};

};