#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class findLargestValInTreeRow {
public:
	vector<int> largestValues(TreeNode* root) {

		if (root == NULL)
			return vector<int>();

		vector<int> largestVals;
		queue<TreeNode*> children;
		children.push(root);

		while (!children.empty()) {

			int size = children.size();
			int maxi = INT_MIN;

			for (int i = 0; i < size; i++) {

				TreeNode* curr = children.front();
				children.pop();

				if(curr->left != NULL)
					children.push(curr->left);
				if(curr->right != NULL)
					children.push(curr->right);

				maxi = max(maxi, curr->val);

			}

			largestVals.push_back(maxi);

		}

		print(largestVals);

		return largestVals;

	};


private:
	void print(vector<int> &ans) {
		for (int j = 0; j < ans.size(); j++) {
			cout << ans[j] << setw(5);
		}
		cout << endl;

		int stop;
		cout << "\t\t\t\t\t";
		cin >> stop;

		cout << "----------------------------" << endl;

	};

	void printQueue(queue<TreeNode*> ans) {
		
		cout << "curr queue:\t";
		while (!ans.empty()) {

			if(ans.front() != NULL)
				cout << ans.front()->val << setw(5);
			ans.pop();

		}

		int stop;
		cout << "\t\t\t\t\t";
		cin >> stop;

		cout << "----------------------------" << endl;

	};


};