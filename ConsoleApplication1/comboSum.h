#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class comboSum {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

		nums = candidates;
		sort(nums.begin(), nums.end());

		dfs(0, 0, target, vector<int>());

		return ans;

	};

private:
	inline bool dfs(int index, int total, int target, vector<int> path) {

		// Base Case(s)
		if (total == target) {
			ans.push_back(path);
			return true;
		}
		if (total > target)
			return true;

		for (int i = index; i < nums.size(); i++) {

			int tempTotal = total + nums[i];

			path.push_back(nums[i]);
			bool result = dfs(i, tempTotal, target, path);
			path.pop_back();

			if (result)
				break;

		}

		return false;

	};

	//-----Global Vars-----
	vector<int> nums;
	vector<vector<int>> ans;
};