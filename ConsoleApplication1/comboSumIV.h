#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class comboSumIV {
public:
	int combinationSum4(vector<int>& nums, int target) {

		// Set everything up first
		sort(nums.begin(), nums.end());
		globalNums = nums;
		for (int i = 0; i < target + 1; i++)
			memo.push_back(-1);
		memo[0] = 1;

		depthFirst(target);
		return memo[target];
	};

private:
	inline int depthFirst(int target) {

		if (memo[target] != -1)
			return memo[target];

		int ans = 0;
		for (int currNum : globalNums) {

			if (target >= currNum)
				ans += depthFirst((target - currNum));
			else 
				break;

		}

		memo[target] = ans;

		return ans;

	};

	//Global Vars
	vector<int> globalNums;
	vector<int> memo;
};