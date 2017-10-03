#pragma once
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class iterativeInorderTraversal {
public:
	vector<int> inorderTraversal(TreeNode* root) {

		TreeNode* ptr = root;

		while (!path.empty() || ptr) {

			printP();
			print();

			if (ptr) {
				path.push(ptr);
				ptr = ptr->left;
			}
			else {
				TreeNode *pNode = path.top();
				ans.push_back(pNode->val);
				cout << "------------" << endl;
				cout << "popping: " << path.top()->val << " and adding it to ans vector" << endl;
				path.pop();
				ptr = pNode->right;
				cout << "ptr points to: " << (ptr ? ptr->val : INT_MIN);
				cout << endl << "------------" << endl;

			}

			cout << endl << endl;

		}

		return ans;
	};

	vector<int> postorderTraversal(TreeNode* root) {
		
		clear();
		ans.clear();

		TreeNode* ptr = root;

		while (!path.empty() || ptr) {

			printP();
			print();

			if (ptr) {
				path.push(ptr);
				ptr = ptr->left;
			}
			else {
				cout << "------------" << endl;
				TreeNode *pNode = path.top()->right;
				ans.push_back(pNode->val);
				
				if (!path.top()->left && !path.top()->right) {
					cout << "popping: " << path.top()->val << " and adding it to ans vector" << endl;
					path.pop();
				}
				ptr = pNode;
				cout << "ptr points to: " << (ptr ? ptr->val : INT_MIN);
				cout << endl << "------------" << endl;

			}

			cout << endl << endl;

		}

		return ans;
	};

private:
	void print() {
		cout << "------------" << endl;
		cout << "ans: ";
		for (int i : ans) {
			cout << i << " ";
		}
		cout << endl << "------------" << endl;
	}
	void printP() {
		cout << "------------" << endl;
		cout << "path: ";
		stack<TreeNode*> temp = path;
		for (int i = 0; i < path.size(); i++) {
			cout << temp.top()->val << " ";
			temp.pop();
		}
		cout << endl << "------------" << endl;
	}

	void clear() {
		while (!path.empty())
			path.pop();
	}

	stack<TreeNode*> path;
	vector<int> ans;
};