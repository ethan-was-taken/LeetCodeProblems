#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class nextPerm {
public:
	void nextPermutation(vector<int>& nums) {

		int index = nums.size() - 1;
		for (int i = nums.size() - 2; i >= 0; i--) {

			cout << "i\t" << i << endl;

			if (nums[i] < nums[i + 1]) {
				index = i;
				break;
			}

		}

		cout << endl << "index\t" << index << endl;

		if (index == nums.size() - 1) {
			sort(nums.begin(), nums.end());
			return;
		}
		
		int i = nums.size() - 1;
		for (; i >= index; i--) {

			cout << "i\t" << i << endl;
			cout << "index\t" << index << endl << endl;


			if (nums[i] > nums[index]) {
				int temp = nums[i];
				nums[i] = nums[index];
				nums[index] = temp;
				break;
			}

		}

		sort(nums.begin() + index + 1, nums.end());

	};
};