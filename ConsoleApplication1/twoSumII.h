#pragma once
#include <iostream>

#include <vector>
#include <algorithm>


using namespace std;

class twoSumII {
public:

	/*
	1.	subtract curr from target -> this is your new target to search for.
	2.	do a binary Search for the new  target
	3.	if its there, return the two indexes, otherwise continue looking
	*/

	vector<int> twoSum(vector<int>& numbers, int target) {

		vector<int> toReturn;

		for (int i = 0; i < numbers.size() - 1; i++) {

			int newTarget = target - numbers[i];

			int index = binarySearch(numbers, i + 1, numbers.size() - 1, newTarget);

			if (index != -1) {
				toReturn.push_back(i + 1);
				toReturn.push_back(index + 1);
				break;
			}
			
		}

		return toReturn;

	};

private:
	inline int binarySearch(vector<int> &nums, int left, int right, int target) {

		int mid = (right + left) / 2;
		cout << "---------------------------" << endl;
		cout << "left:\t" << left << endl;
		cout << "mid:\t" << mid << endl;
		cout << "right:\t" << right << endl;
		cout << "target:\t" << target << endl;


		if (nums[mid] == target) {
			cout << "returning mid" << endl;
			return mid;
		}
		else if (right > left && nums[mid] < target) {
			cout << "right > left && nums[mid] < target" << endl;
			return binarySearch(nums, mid + 1, right, target);
		}
		else if (right > left && nums[mid] > target) {
			cout << "right > left && nums[mid] > target" << endl;
			return binarySearch(nums, left, mid - 1, target);
		}
		
		cout << "-1" << endl;
		return -1;

	}

};
