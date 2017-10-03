#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class findDuplicateNum {
public:
	int findDuplicate(vector<int>& nums) {
		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			if (i < nums.size() - 1 && nums[i] == nums[i + 1])
				return nums[i];
		}

		int n = nums.size() - 1;
		int gaussNum = (int)(pow(n, 2) + n) / 2;

		int ans = sum - gaussNum;
		if (ans <= 0 || ans >= n)
			return findDup(nums);

		return ans;

	}

private:
	inline int findDup(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[i] == nums[j])
					return nums[i];
			}
		}
	}
};