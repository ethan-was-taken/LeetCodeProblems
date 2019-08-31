#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include <algorithm>
#include <random>

#define ASCII_A 'a'
#define STRING_INIT "~"

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class SmallestStringFromLeaf {
public:
	string smallestFromLeaf(TreeNode* root) {
		
		smallestString = STRING_INIT;
		curr = "";

		dfs(root);

		return smallestString != STRING_INIT ? smallestString : "";

	};
	
private:
	string smallestString;
	string curr;

	void dfs(TreeNode* currNode) {

		if (!currNode)
			return;
		
		curr.push_back(((char) currNode->val + ASCII_A));

		if (isLeaf(currNode))
			updateSmallestString(curr);

		dfs(currNode->left);
		dfs(currNode->right);

		curr.pop_back();

	};

	inline bool isLeaf(TreeNode* currNode) {
		return !currNode->left && !currNode->right;
	};

	inline void updateSmallestString(string curr) {

		reverse(curr.begin(), curr.end());

		bool isCurrSmaller = lexicographical_compare(curr.begin(), curr.end(), smallestString.begin(), smallestString.end());
		smallestString = isCurrSmaller ? curr : smallestString;
			
	};

};