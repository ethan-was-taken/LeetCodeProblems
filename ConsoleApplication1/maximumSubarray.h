#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class maximumSubarray {
public:
	int maxSubArray(vector<int>& nums) {

		int max = INT_MIN;
		int currMax = 0;

		for (int i = 0; i < nums.size(); i++) {

			bool wasNegative = currMax < 0;
			currMax += nums[i];
			bool isPositive = currMax >= 0;

			// if currMax went from negative to Positive OR
			// if we have a negative number and the next number is positive
			if (flipped(wasNegative, isPositive) || isNextLarger(!isPositive, nums[i], currMax))
				currMax = nums[i];

			max = (max < currMax) ? currMax : max;

		}

		return max;

	};

private:
	// More code, but easier to read
	// Did the currMax "flip" from negative to positive? -> true if yes otherwise false
	inline bool flipped(bool wasNegative, bool isPositive) {
		return wasNegative && isPositive;
	};
	
	// if currMax is negative, is the next value in nums larger than the current value?
	// returns true if yes, otherwise false
	inline bool isNextLarger(bool isNegative, int curr, int currMax ) {
		return isNegative && (curr >= currMax);
	};
};