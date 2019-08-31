#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "treeNode.h"
#include "printer.h"

using namespace std;

typedef long long loong;

class averageLevelsBinaryTree {
public:
	vector<double> averageOfLevels(TreeNode* root) {

		vector<pair<loong, loong>> levelSum;
		levelSum.push_back(pair<loong, loong>());
		getLevelSum(root, levelSum, 0);

		return getAverages(levelSum);

	};

private:
	inline void getLevelSum(TreeNode* curr, vector<pair<loong, loong>> &levelSum, int level) {

		if (!curr)
			return;

		if (levelSum.size() <= level)
			levelSum.push_back(pair<loong, loong>());

		levelSum[level].first += curr->val;
		levelSum[level].second++;

		getLevelSum(curr->left, levelSum, level + 1);
		getLevelSum(curr->right, levelSum, level + 1);

	};

	inline vector<double> getAverages(vector<pair<loong, loong>> &levelSum) {
		vector<double> averages(levelSum.size(), 0);
		for (int i = 0; i < levelSum.size(); i++)
			averages[i] = (double)levelSum[i].first / levelSum[i].second;
		return averages;
	};

};