#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class bstIterator {
public:
	//BSTIterator
	bstIterator(TreeNode *root) {

		if (root == NULL) {
			currPos = -1;
			return;
		}

		dfs(root);
		/*dfsLeft(root->left);
		sorted.push_back(root->val);
		dfsRight(root->right);*/

		for (int i : sorted) {
			cout << i << "\t";
		}
		cout << endl << endl;

		currPos = 0;
		
	};

	/** @return whether we have a next smallest number */
	bool hasNext() {
		//return currPos >= 0;
		return currPos < sorted.size();
	};

	/** @return the next smallest number */
	int next() {
		//return sorted[currPos--];
		return sorted[currPos++];
	};

private:
	inline void dfs(TreeNode *root) {

		if (root == NULL)
			return;

		dfs(root->left);
		sorted.push_back(root->val);
		dfs(root->right);

	};

	inline void dfsLeft(TreeNode *root){

		if (root == NULL)
			return;

		/*dfsLeft(root->left);
		sorted.push_back(root->val);
		dfsLeft(root->right);*/

		dfsLeft(root->right);
		sorted.push_back(root->val);
		dfsLeft(root->left);
	};

	inline void dfsRight(TreeNode *root) {

		if (root == NULL)
			return;
		
		/*dfsRight(root->right);
		sorted.push_back(root->val);
		dfsRight(root->left);*/

		dfsRight(root->left);
		sorted.push_back(root->val);
		dfsRight(root->right);

	};

	vector<int> sorted;
	int currPos;

};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/
