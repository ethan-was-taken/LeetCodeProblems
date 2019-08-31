#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class longestIncSequence {
public:
	static int findLengthOfLCIS(vector<int>& nums) {
		
		//sanity check
		if (nums.size() <= 1)
			return nums.size();

		int maxi = INT_MIN;
		int count = 1;
		for (int i = 0; i < nums.size() - 1; i++) {
			if (nums[i + 1] > nums[i]) {
				count++;
			}
			else {
				maxi = max(count, maxi);
				count = 1;
			}
		}

		maxi = max(count, maxi);

		return maxi;

	};

private:

};