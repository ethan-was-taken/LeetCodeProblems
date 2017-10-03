#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class findMin_153 {
public:
	int findMin(vector<int>& nums) {

		return binarySearch(nums, 0, nums.size() - 1);

	};

private:
	inline int binarySearch(vector<int>& nums, int left, int right) {

		int mid = (right - left) / 2 + left;
		
		cout << endl;
		cout << "l:\t" << left << endl;
		cout << "m:\t" << mid << endl;
		cout << "r:\t" << right << endl;

		if (mid <= left) {
			cout << 1 << endl;
			return min(min(nums[left], nums[right]), nums[mid]);
		}
				
		if (nums[mid - 1] > nums[mid]) {
			cout << 2 << endl;
			return nums[mid];
		}
		else if (nums[mid + 1] < nums[mid]) {
			cout << 3 << endl;
			return nums[mid + 1];
		}

		if (nums[mid - 1] < nums[mid] && nums[right] > nums[mid]) {
			cout << 4 << endl;
			return binarySearch(nums, left, mid - 1);
		}

		cout << 5 << endl;
		return binarySearch(nums, mid + 1, right);

	}

};