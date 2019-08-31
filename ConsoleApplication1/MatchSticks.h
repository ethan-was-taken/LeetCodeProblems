#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

class MatchSticksToSquare {
public:
	bool makesquare(vector<int> &nums) {
		setup(nums);
		dfs(0);
		return isSquarePossible;
	};

private:
	vector<int> nums;
	bool isSquarePossible;
	int totalLength;

	void setup(vector<int> &nums) {
		this->nums = nums;
		isSquarePossible = false;
		totalLength = 0;
	}

	void dfs(int startIndex) {

		if (startIndex == nums.size() && !isSquarePossible) {
			isSquarePossible = totalLength == 0;
			return;
		}

		for (int i = startIndex; i < nums.size(); i++) {

			// Go up
			totalLength += nums[i];
			dfs(startIndex + 1);
			totalLength -= nums[i];

			// Go left
			totalLength += nums[i];
			dfs(startIndex + 1);
			totalLength -= nums[i];

			// Go down
			totalLength -= nums[i];
			dfs(startIndex + 1);
			totalLength += nums[i];

			// Go right
			totalLength -= nums[i];
			dfs(startIndex + 1);
			totalLength += nums[i];

		}
			

	}
};