#pragma once
#include <iostream>
#include <vector>

using namespace std;

class insertPos {
public:
	int searchInsert(vector<int>& nums, int target) {

		int res = binarySearch(nums, target, 0, nums.size() - 1);

		return (res < 0) ? 0 : res;

	};

private:
	inline int binarySearch(vector<int>& nums, int target, int left, int right) {

		int mid = (right - left) / 2 + left;

		if (nums[mid] == target)
			return mid;

		if (left < right) {

			if (nums[mid] < target)
				return binarySearch(nums, target, mid + 1, right);
			else if (nums[mid] > target)
				return binarySearch(nums, target, left, mid - 1);

		}

		return (nums[right] < target) ? right + 1 : right;

	};

};
