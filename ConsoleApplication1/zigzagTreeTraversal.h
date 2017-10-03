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

class zigzagTreeTraversal {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

		if (!root)
			return ans;

		bfs(root, 0);

		print();

		return ans;

	};

private:
	void bfs(TreeNode* curr, int level) {

		if (!curr)
			return;

		cout << "level: " << level << endl;
		cout << "ans.size: " << ans.size() << endl;

		print();

		if (ans.size() <= level) {
			ans.push_back(vector<int>());
		}

		if (level % 2 == 0) {
			ans[level].push_back(curr->val);
		}
		else {
			ans[level].insert(ans[level].begin(), curr->val);
		}

		bfs(curr->left, level + 1);
		bfs(curr->right, level + 1);


	};

	void print() {

		for (int i = 0; i < ans.size(); i++) {

			for (int curr : ans[i]) {
				cout << curr << " ";
			}

			cout << endl;

		}

		cout << endl;

		stopper();

	}

	void stopper() {
		int stop;
		cout << "\t\t\t\t\t";
		cin >> stop;
	};

	vector<vector<int>> ans;

};