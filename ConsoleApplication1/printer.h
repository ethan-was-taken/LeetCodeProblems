#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class printer {
public:
	
	/*static void print(TreeNode* ans) {
		cout << "ans: " << (ans ? to_string(ans->val) : "NULL") << endl;
	};*/

	static void print(bool ans) {
		cout << (ans ? "true" : "false") << endl;
	};

	static void print(int ans) {
		cout << "ans: " << ans << endl;
	};

	static void print(string ans) {
		cout << "ans: " << ans << endl;
	};

	static void print(vector<int> ans) {
		for (auto i : ans) {
			cout << i << "\t";
		}
	};

	static void print(vector<string> ans) {
		for (auto i : ans) {
			cout << i << "\t";
		}
	};

	static void print(vector<vector<int>> ans) {
		for (int i = 0; i < ans.size(); i++) {

			for (int j = 0; j < ans[i].size(); j++)
				cout << ans[i][j] << " ";

			cout << endl;

		}
	};

	static void print(vector<vector<string>> ans) {
		for (int i = 0; i < ans.size(); i++) {

			for (int j = 0; j < ans[i].size(); j++)
				cout << ans[i][j] << " ";

			cout << endl;

		}
	};

	/*static void postorder(TreeNode* p, int indent = 0) {

		if (p != NULL) {
			if (p->right) {
				postorder(p->right, indent + 4);
			}
			if (indent) {
				cout << setw(indent) << ' ';
			}
			if (p->right)
				cout << " /\n" << setw(indent) << ' ';
			cout << p->val << "\n ";
			if (p->left) {
				cout << setw(indent) << ' ' << " \\\n";
				postorder(p->left, indent + 4);
			}
		}
		cout << endl;
	}*/

	static void postorder(treeNode* p, int indent = 0) {

		if (p != NULL) {
			if (p->right) {
				postorder(p->right, indent + 4);
			}
			if (indent) {
				cout << setw(indent) << ' ';
			}
			if (p->right)
				cout << " /\n" << setw(indent) << ' ';
			cout << p->value << "\n ";
			if (p->left) {
				cout << setw(indent) << ' ' << " \\\n";
				postorder(p->left, indent + 4);
			}
		}
		cout << endl;
	}

	//static void in(TreeNode* node) {

	//	if (node == NULL)
	//		return;

	//	/* first recur on left child */
	//	in(node->left);

	//	/* then print the data of node */
	//	cout << node->val << "\t";

	//	/* now recur on right child */
	//	in(node->right);

	//};

	//static void pre(TreeNode* node) {

	//	if (node == NULL)
	//		return;

	//	/* then print the data of node */
	//	cout << node->val << "\t";

	//	/* first recur on left child */
	//	pre(node->left);
	//	/* now recur on right child */
	//	pre(node->right);

	//};

	
	/*static void print(ListNode* ans) {
		while (ans) {
			cout << ans->val << " " << endl;
			ans = ans->next;
		}
	};*/
	
};