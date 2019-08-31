#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class PeakElement {
public:
	// Can do in O(logn)
	int findPeakElement(vector<int>& nums) {

		if (nums.size() == 1)
			return 0;

		for (int i = 0; i < nums.size(); i++) {
			if (isPeak(nums, i))
				return i;
		}

		return 0;

	};

private:
	inline bool isPeak(vector<int> &nums, int currPos) {
		if (currPos == 0)
			return nums[currPos] > nums[1];
		else if (currPos == nums.size() - 1)
			return nums[currPos] > nums[currPos - 1];		
		return nums[currPos] > nums[currPos - 1] && nums[currPos] > nums[currPos + 1];
	};

};
