#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <unordered_set>


using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class treePaths {
public:
	vector<string> binaryTreePaths(TreeNode* root) {

		if (root == NULL) 
			return vector<string>();
		
		vector<string> paths;
		if (isLeaf(root)) {
			paths.push_back(to_string(root->val));
			return paths;
		}

		dfs(root, paths, "");
		
		return paths;

	};

private:
	void dfs(TreeNode* curr, vector<string> &paths, string path) {
		
		if (curr == NULL)
			return;
		if (isLeaf(curr)) {
			string toAdd = path.substr(0, path.size() - 2) + "->" + to_string(curr->val);
			paths.push_back(toAdd);
			return;
		}

		cout << "path:\t" << path << endl;


		string newPath = path;
		newPath += to_string(curr->val) + "->";

		cout << "newPath:\t" << newPath << endl;

		stopper();

		dfs(curr->left, paths, newPath);
		dfs(curr->right, paths, newPath);

	};

	inline bool isLeaf(TreeNode* curr) {
		return curr->left == NULL && curr->right == NULL;
	};

	void stopper() {

		int stop;
		cout << "\t\t\t\t\t";
		cin >> stop;

	};

	// Global shiettttt
	unordered_set<string> vals;

};