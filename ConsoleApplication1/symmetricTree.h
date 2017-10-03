#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class symmetricTree {
public:
	bool isSymmetric(TreeNode* root) {

		if (!root)
			return true;
		else if (!root->left && !root->right)
			return true;

		vector<int> left;
		if(root->left)
			dfsLeft(root->left, left);

		print(left);

		vector<int> right;
		if (root->right)
			dfsRight(root->right, right);

		print(right);
		
		return isVectorSymmetric(left, right);
	};	

private:
	inline void dfsLeft(TreeNode* root, vector<int> &input) {

		if (!root) {
			input.push_back(NULL);
			return;
		}

		input.push_back(root->val);

		dfsLeft(root->left, input);
		dfsLeft(root->right, input);

	};

	inline void dfsRight(TreeNode* root, vector<int> &input) {

		if (!root) {
			input.push_back(NULL);
			return;
		}

		input.push_back(root->val);

		dfsRight(root->right, input);
		dfsRight(root->left, input);

	};

	inline void print(vector<int> in) {
		cout << "-------------------------" << endl;
		cout << "1dVector: ";
		for (int curr : in) {
			cout << curr << " ";
		}
		cout << endl;
		cout << "-------------------------" << endl;
	};
	
	inline bool isVectorSymmetric(vector<int> left, vector<int> right) {

		if (left.empty() || right.empty())
			return false;

		for (int i = 0; i < left.size(); i++) {
			//cout << "checking: " << currLevel[i] << " " << currLevel[j] << endl;
			if (left[i] != right[i])
				return false;		
			
		}

		return true;
	};

};