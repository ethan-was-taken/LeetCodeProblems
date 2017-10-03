#pragma once
#include <vector>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class levelOrderTraverse {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {

		if (root == NULL)
			return ans;

		levelOrder(root, 0);

		return ans;
	};

private:
	void levelOrder(TreeNode* root, int level) {

		// Bass Cass
		if (root == NULL)
			return;
		
		if (ans.empty() || ans.size() - 1 < level) {
			vector<int> newRow;
			newRow.push_back(root->val);
			ans.push_back(newRow);
		}
		else if (!ans[level].empty())
			ans[level].push_back(root->val);
		
		levelOrder(root->left, level + 1);
		levelOrder(root->right, level + 1);

	};

	//---Global Vars---
	vector<vector<int>> ans;

};