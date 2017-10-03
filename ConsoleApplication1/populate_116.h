#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


class populate_116 {
public:
	void connect(TreeLinkNode *root) {

		if (!root)
			return;

		int height = findBSTHeight(root, 1);
		populateTreeLevels(height);

		dfs(root, 0);

		setNext();

	};

private:

	inline int findBSTHeight(TreeLinkNode *root, int level) {

		if (!root || !root->left)
			return level;

		return findBSTHeight(root->left, level + 1);

	};

	// More code in the long run, but IMO makes the program easier to read
	inline void populateTreeLevels(int height) {

		for (int i = 0; i < height; i++)
			treeLevels.push_back(vector<TreeLinkNode *>());

	}

	inline void dfs(TreeLinkNode *root, int level) {

		if (!root)
			return;

		treeLevels[level].push_back(root);

		dfs(root->left, level + 1);
		dfs(root->right, level + 1);

	};

	inline void setNext() {

		// Start at 1 beacuse there is no need to edit the roots next value
		for (int i = 1; i < treeLevels.size(); i++) {
			// UpperBound is treeLevels[i].size() - 1 so that we dont set the last Nodes next
			for (int j = 0; j < treeLevels[i].size() - 1; j++)
				treeLevels[i][j]->next = treeLevels[i][j + 1];

		}

	};

	//-----Global Vars-----
	vector<vector<TreeLinkNode *>> treeLevels;

};