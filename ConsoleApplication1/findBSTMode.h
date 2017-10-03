#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class findBSTMode {
public:
	vector<int> findMode(TreeNode* root) {
		
		dfs(root);
		
		vector<int> ans;
		int largest = INT_MIN;
		
		// Find out what the modes are
		unordered_map<int, int>::iterator it = instances.begin();
		for (; it != instances.end(); it++) {
			if (it->second > largest)
				largest = it->second;
		}

		it = instances.begin();
		for (; it != instances.end(); it++) {
			if (it->second == largest)
				ans.push_back(it->first);
		}

		return ans;

	};

private:
	void dfs(TreeNode* root) {

		if (!root)
			return;

		if (instances.find(root->val) == instances.end())
			instances.insert(pair<int, int>(root->val, 1));
		else {
			instances.find(root->val)->second++;
		}

		dfs(root->left);
		dfs(root->right);

	};

	unordered_map<int, int> instances;
};