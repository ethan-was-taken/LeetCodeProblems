#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include <algorithm>
#include <random>

#define ASCII_0 48
#define ASCII_9 56

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class PreorderRecovery {
public:
	TreeNode* recoverFromPreorder(string s) {
		
		processString(s);
		
		nextNodeIndex = 0;
		root = new TreeNode(nodes.front().second);

		//preorderTraversal();

		return root;

	};

private:
	// pair.first = level
	// pair.second = node value
	vector<pair<int, int>> nodes;
	int nextNodeIndex;

	TreeNode* root;

	void processString(string &input) {

		vector<string> split;

		int lastNodeIndex = 0;
		for (int i = 1; i < input.size(); i++) {
			if (input[i - 1] != '-' && input[i] == '-') {
				split.push_back(input.substr(lastNodeIndex, i - lastNodeIndex));
				lastNodeIndex = i;
			}
		}

		for (string curr : split) {
			int level = getNodeLevel(curr, 0);
			int nodeVal = stoi(curr.substr(level));
			nodes.push_back(make_pair(level, nodeVal));
		}

	};

	inline int getNodeLevel(const string& in, int startIndex) {
		while (in[startIndex] < ASCII_0 || in[startIndex] > ASCII_9)
			startIndex++;
		return startIndex;
	};

	void preorderTraversal(TreeNode* currNode) {
				
		if (isLeaf(nextNodeIndex)) {
			addNode(currNode, nextNodeIndex);
			nextNodeIndex++;
			return;
		}
		
		int currLevel = nextNodeIndex - 1;		
		
		TreeNode* nextNodePtr = addNode(currNode, nextNodeIndex);
		nextNodeIndex++;
		preorderTraversal(nextNodePtr);

		// ensure we're at the correct level before moving on
		if (currLevel >= nextNodeIndex)
			return;

		TreeNode* nextNodePtr = addNode(currNode, nextNodeIndex);
		nextNodeIndex++;
		preorderTraversal(nextNodePtr);

		

	};

	inline bool isLeaf(int index) {
		
		if (index >= nodes.size())
			return true;
		else if (index == 0 && nodes.size() > 1)
			return false;
		else if (index == 0 && nodes.size() <= 1)
			return true;

		return nodes[index].first > nodes[index + 1].first;

	};

	inline TreeNode* addNode(TreeNode* currNode, int nextNodeIndex) {
		
		TreeNode* nextNode = getNextNode(nextNodeIndex);

		//if()

		return nextNode;

	};

	inline TreeNode* getNextNode(int index) {
		return index < nodes.size() ? new TreeNode(nodes[index].second) : NULL;
	};

};