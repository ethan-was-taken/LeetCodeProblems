#pragma once
#include <iostream>
#include <iomanip>
#include <string>
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

class serializeDeserializeBinaryTree {
public:
	// Encodes a tree to a single string.
	// NOTE: not as efficient as it could be
	string serialize(TreeNode* root) {

		if (root == NULL)
			return "N";

		string serial = "";
		queue<TreeNode*> children;
		children.push(root);

		while (!children.empty()) {

			bool isRowNull = true;

			int size = children.size();
			for (int i = 0; i < size; i++) {

				TreeNode* curr = children.front();
				children.pop();

				if (curr == NULL) {
					serial += "N, ";
					continue;
				}

				if (curr->left != NULL || curr->right != NULL)
					isRowNull = false;

				serial += to_string(curr->val) + ", ";

				children.push(curr->left);
				children.push(curr->right);

			}

			serial += "!, ";

			if (isRowNull) {
				int end = 3 * (size + 1) * 2;
				serial.substr(0, serial.size() - end);
				break;
			}

		}

		return serial.substr(0, serial.size() - 2);

	};

	TreeNode* deserialize(string data) {

		vector<vector<TreeNode*>> nodes;
		nodes.push_back(vector<TreeNode*>());

		makeVector(nodes, data);

		if (nodes.size() == 1)
			return nodes[0][0];

		for (int i = 0; i < nodes.size() - 1; i++) {

			auto curr = nodes[i];
			auto next = nodes[i + 1];
			int nextIndex = 0;

			for (int j = 0; j < curr.size() && nextIndex < next.size(); j++) {

				if (curr[j] == NULL)
					continue;

				curr[j]->left = next[nextIndex++];
				curr[j]->right = next[nextIndex++];

			}

		}

		return nodes[0][0];

	};

private:
	inline void makeVector(vector<vector<TreeNode*>> &nodes, string &data) {

		for (int i = 0, j = 0; i < data.size(); i = j + 1) {

			j = i;
			while (j < data.size() && data[j] != ',')
				j++;

			// Handle new lines -> add a new vector
			if (data[j - 1] == '!')
				nodes.push_back(vector<TreeNode*>());
			// Handle null values
			else if (data[j - 1] == 'N')
				nodes.back().push_back(NULL);
			else {
				TreeNode* temp = new TreeNode(stoi(data.substr(i, j)));
				nodes.back().push_back(temp);
			}

		}

	};

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));