#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class minSubArraySum {
public:
	int minSubArrayLen(int s, vector<int>& nums) {

		if (nums.empty())
			return 0;

		int lptr = 0;
		int rptr = 1;

		int minLength = INT_MAX;
		int currSum = nums[lptr] + nums[rptr];

		while (lptr < nums.size() && rptr < nums.size() - 1 && lptr <= rptr) {

			if (nums[lptr] >= s || nums[rptr] >= s)
				return 1;

			// set Rptr to the correct position
			setSumAndRptr(nums, s, lptr, rptr, currSum);
			
			// set Lptr to the correct position
			setSumAndLptr(nums, s, lptr, rptr, currSum);
			
			int tempLength = rptr - lptr + 1;

			// only set minLength if the range is valid
			if (currSum >= s)
				minLength = (minLength > tempLength) ? tempLength : minLength;

			// make sure currSum is correct
			currSum -= nums[lptr];
			lptr++;

		}

		return (minLength == INT_MAX) ? 0 : minLength;
	};

private:

	// Finds a position in nums array where the sum of the subarray (between lptr and rptr) is >= s
	// Returns the new currSum and the new position of the rptr
	inline pair<int, int> setSumAndRptr(vector<int>& nums, int s, int &lptr, int &rptr, int &currSum) {

		for (int i = lptr; i < nums.size() && currSum < s; i++) {
			
			rptr++;
			if (rptr >= nums.size())
				break;

			currSum += nums[rptr];

		}
		
		return pair<int, int>(currSum, rptr);
	};

	// Similar to setSumAndRptr except this function trims all the fat off the subarray.
	//  This allows the subarray to be as close to s as possible
	// Returns the new currSum and the new position of the lptr
	inline pair<int, int> setSumAndLptr(vector<int>& nums, int s, int &lptr, int &rptr, int &currSum) {

		for (int i = lptr; i < rptr; i++) {

			int toRemove = nums[lptr];

			if ((currSum - toRemove) < s)
				break;

			currSum -= toRemove;
			lptr++;

		}

		return pair<int, int>(currSum, lptr);
	};

};