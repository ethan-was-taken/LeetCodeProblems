#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <stack>

#include "printer.h"
#include "stopper.h"
#include "TreeNode.h"

using namespace std;

class pathSumII {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		dfs(root, sum, vector<int>(), 0);
		return toReturn;
	};

private:
	void dfs(TreeNode* curr, int sum, vector<int> currPath, int currSum) {
		
		if (!curr)
			return;
		
		//do stuff
		currPath.push_back(curr->val);
		currSum += curr->val;

		if (currSum == sum && isLeaf(curr)) {
			toReturn.push_back(currPath);
			return;
		}

		dfs(curr->left, sum, currPath, currSum);
		dfs(curr->right, sum, currPath, currSum);
				
	};

	inline bool isLeaf(TreeNode* curr) {
		return !curr->left && !curr->right;
	};

	vector<vector<int>> toReturn;

};