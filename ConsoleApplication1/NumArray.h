#pragma once
#include <iostream>
#include <vector>

#include "stopper.h"

using namespace std;

class NumArray {
public:
	NumArray(vector<int> nums) {
		
		int prev = 0;
		for (int i = nums.size() - 1; i >= 0; i--) {
			sums.push_back(nums[i] + prev);
			prev = sums.back();
		}

		reverse(sums.begin(), sums.end());

	};

	int sumRange(int i, int j) {
		// Some checking first to make sure i is the smaller of the two
		checkInputForSumRange(i, j);

		if ((j == sums.size() - 1))
			return sums[i];

		return sums[i] - sums[j + 1];

	};

private:
	vector<int> sums;

	inline void checkInputForSumRange(int &i, int &j) {
		int temp = i;
		i = (i < j) ? i : j;
		j = (i == j) ? temp : j;
	};

};

/**
* Your NumArray object will be instantiated and called as such:
* NumArray obj = new NumArray(nums);
* int param_1 = obj.sumRange(i,j);
*/