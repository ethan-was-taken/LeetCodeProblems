#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>

#include "treeNode.h"
//#include "temp.h"

using namespace std;

class printer {
public:
	static void print(TreeNode* ans) {
		cout << "ans: " << (ans ? to_string(ans->val) : "NULL") << endl;
	};

	/*static void print(ListNode* ans) {
		cout << "ans: ";
		while (ans != NULL) {
			cout << (ans ? to_string(ans->val) : "NULL") << " ";
			ans = ans->next;
		}
		cout << endl;
		
	};*/

	/*template<typename T>
	static void print(GenericListNode<T>* ans) {
		cout << (!ans ? "NULL" : "") << endl;
		while (ans != NULL) {
			cout << (ans ? to_string(ans->val) : "NULL") << " ";
			ans = ans->next;
		}
		cout << endl;

	};*/

	static void print(list<int> ans) {
		cout << "vector:\t";
		for (auto i : ans) {
			cout << i << " ";
		}
		cout << endl;
	};

	static void print(bool ans) {
		cout << (ans ? "true" : "false") << endl;
	};

	static void print(int ans) {
		cout << ans << endl;
	};

	static void print(string ans) {
		cout << "ans: " << ans << endl;
	};

	static void print(pair<int, int> ans) {
		cout << "ans: " << ans.first << " " << ans.second << endl;
	};

	static void print(stack<TreeNode*> ans) {
		vector<int> temp;
		while (!ans.empty()) {
			temp.push_back(ans.top()->val);
			ans.pop();
		}
		reverse(temp.begin(), temp.end());
		printer::print<int>(temp);
	};

	template<typename T>
	static void print(stack<T> ans) {
		while (!ans.empty()) {
			cout << ans.top() << endl;
			ans.pop();
		}
	};

	static void print(vector<bool> ans) {
		for (auto i : ans) {
			cout << (i ? "true" : "false") << " ";
		}
		cout << endl;
	};

	template<typename E>
	static void print(vector<E> ans) {
		for (E i : ans) {
			cout << left<< setw(5) << i << " ";
		}
		cout << endl;
	};

	static void print(vector<TreeNode*> ans) {
		cout << "vector:\t";
		for (TreeNode* i : ans) {
			cout << i->val << " ";
		}
		cout << endl;
	};

	static void print(vector<pair<int, int>> &ans) {
		for (auto i : ans) {
			string toPrint = "";
			toPrint.append(to_string(i.first));
			toPrint.append(", ");
			toPrint.append(to_string(i.second));
			toPrint.append(" ");
			cout << left << setw(5) << toPrint;
		}
		cout << endl;
	};

	static void printTwoDVector(vector<vector<bool>> ans) {
		for (int i = 0; i < ans.size(); i++) {

			for (int j = 0; j < ans[i].size(); j++)
				cout << ans[i][j] << " ";

			cout << endl;

		}
	};

	static void print(vector<vector<int>> ans) {
		for (int i = 0; i < ans.size(); i++) {

			for (int j = 0; j < ans[i].size(); j++)
				cout << left<< setw(5) << ans[i][j] << " ";

			cout << endl;

		}
	};

	static void postorder(TreeNode* p, int indent = 0) {

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
	};

	static void print(unordered_set<int> ans) {
		for (auto i : ans)
			cout << i << " ";
		cout << endl;
	};
	
};