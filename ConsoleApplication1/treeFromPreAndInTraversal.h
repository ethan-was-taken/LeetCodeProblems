#pragma once
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class treeFromPreAndInTraversal {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

		/*
		preorderTraversal(TreeNode* curr, TreeNode* construct, vector<int>& preorder, vector<int>& inorder, int &i, int &j):
		1.	start construction by doing a depth first starting at the root and going left (traversal by preorder?)
			NOTE: add visited nodes to a hashmap

		2.	on recursion: if pre[i] == in[j]:
				increase j until you reach a node you havent visited
				and increase i by 1
				return;
				(this is how you know you've reached a leaf!)
		
		3.	???

		4.	PROFIT

		*/

		in = inorder;
		pre = preorder;

		if (preorder.size() == 1) {
			return new TreeNode(pre[0]);
		}
		if (preorder.size() == 2) {
			return handleEdgeCase();
		}

		TreeNode* tree = new TreeNode(pre[0]);
		tempTree = tree;
		int preIndex = 1;
		int inIndex = 0;
		visited.insert(pre[0]);

		dfs(tree, preIndex, inIndex);

		cout << endl << "------------------------------" << endl;
		postorder(tree);

		return tree;

	};

	void inOrderPrint(TreeNode* node, vector<int> &toReturn) {

		if (node == NULL)
			return;

		/* first recur on left child */
		inOrderPrint(node->left, toReturn);

		/* then print the data of node */
		cout << node->val << "\t";
		toReturn.push_back(node->val);

		/* now recur on right child */
		inOrderPrint(node->right, toReturn);

	};

	void preOrderPrint(TreeNode* node, vector<int> &toReturn) {

		if (node == NULL)
			return;

		/* then print the data of node */
		cout << node->val << "\t";
		toReturn.push_back(node->val);

		/* first recur on left child */
		preOrderPrint(node->left, toReturn);
		/* now recur on right child */
		preOrderPrint(node->right, toReturn);

	};

	void postorder(TreeNode* p, int indent = 0) {

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

private:
	void dfs(TreeNode* curr, int &preIndex, int &inIndex) {

		if (visited.find(in[inIndex]) != visited.end()) {
			
			cout << "we're at a leaf" << endl;
			postorder(tempTree);
			cout << "------------------------------" << endl;

			while (inIndex < in.size() - 1 && visited.find(in[++inIndex]) != visited.end());
			return;
		}
		if (preIndex >= pre.size() - 1 || inIndex >= in.size() - 1) {

			cout << "we're at end of line" << endl;
			if (curr == NULL)
				cout << "NULLLLL" << endl;
			else
				cout << curr->val << endl;

			postorder(tempTree);
			cout << "------------------------------" << endl;

			return;
		}

		cout << "before Left" << endl;
		postorder(tempTree);
		stopper();
		cout << "------------------------------" << endl;

		// Go left
		if (preIndex < pre.size()) {
			curr->left = new TreeNode(pre[preIndex]);
			visited.insert(pre[preIndex]);
			preIndex++;
			dfs(curr->left, preIndex, inIndex);
		}

		cout << "before right" << endl;
		postorder(tempTree);
		stopper();
		cout << "------------------------------" << endl;

		// Go Right
		if (preIndex < pre.size()) {
			curr->right = new TreeNode(pre[preIndex]);
			visited.insert(pre[preIndex]);
			preIndex++;
			dfs(curr->right, preIndex, inIndex);
		}

		cout << "after right" << endl;
		postorder(tempTree);
		stopper();
		cout << "------------------------------" << endl;

	};

	TreeNode* handleEdgeCase() {

		TreeNode* tree = new TreeNode(pre[0]);

		if(pre[1] == in[1])
			tree->right = new TreeNode(pre[1]);
		else
			tree->left = new TreeNode(pre[1]);

		postorder(tree);

		return tree;

	};

	void stopper() {

		int stop;
		cout << "\t\t\t\t\t";
		cin >> stop;

	};

	// -----Global Vars-----
	vector<int> in;
	vector<int> pre;

	TreeNode* tempTree;

	unordered_set<int> visited;

};