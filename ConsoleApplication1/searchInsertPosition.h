#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class searchInsertPosition {
public:
	static int searchInsert(vector<int>& nums, int target) {
		return searchInsert(nums, target, 0, nums.size() - 1);
	};

private:
	static int searchInsert(vector<int>& nums, int target, int lptr, int rptr) {

		int mptr = (lptr + rptr) / 2;
		if (nums[mptr] == target)
			return mptr;
		if (lptr > rptr)
			return lptr;

		if (nums[mptr] < target) 
			return searchInsert(nums, target, mptr + 1, rptr);
		
		return searchInsert(nums, target, lptr, mptr - 1);

	};

};