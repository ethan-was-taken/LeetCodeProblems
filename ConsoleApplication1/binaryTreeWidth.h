#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

#include "treeNode.h"
#include "printer.h"
#include "stopper.h"

using namespace std;

struct NodeInfo{
	int index;
	int level;
	NodeInfo(int i, int l) : index(i), level(l) {};
};

class binaryTreeWidth {
public:
	static int widthOfBinaryTree(TreeNode* root) {

		int maxWidth = INT_MIN;
		vector<pair<int, int>> widths;
		widths.push_back(pair<int, int>(0, 0));
		dfs(widths, root, NodeInfo(0, 0), maxWidth);

		return maxWidth == INT_MIN ? 0 : maxWidth;

	};

private:
	static void dfs(vector<pair<int, int>> &widths, TreeNode* curr, NodeInfo info, int &maxWidth) {

		if (!curr)
			return;

		if (widths.size() - 1 < info.level)
			widths.push_back(pair<int, int>(info.index, info.index));

		widths[info.level].first = min(widths[info.level].first, info.index);
		widths[info.level].second = max(widths[info.level].second, info.index);
		
		setMaxWidth(widths[info.level], maxWidth);

		dfs(widths, curr->left, NodeInfo(getLeftIndex(info), info.level + 1), maxWidth);
		dfs(widths, curr->right, NodeInfo(getRightIndex(info), info.level + 1), maxWidth);

	};

	static inline int getLeftIndex(NodeInfo &info) {
		return info.index * 2 + 1;
	};

	static inline int getRightIndex(NodeInfo &info) {
		return getLeftIndex(info) + 1;
	};

	static inline void setMaxWidth(pair<int, int> &indicies, int &maxWidth) {
		int currWidth = indicies.second - indicies.first + 1;
		maxWidth = max(currWidth, maxWidth);
	};

};