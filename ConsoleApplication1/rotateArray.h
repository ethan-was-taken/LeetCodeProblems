#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class rotateArray {
public:
	void rotate(vector<int>& nums, int k) {

		int size = nums.size();
		if (size == 0 || size == 1 || k == size || k == 0)
			return;

		if (k > size)
			k -= size;

		vector<int> temp;
		for (int i = size - k; i < size; i++)
			temp.push_back(nums[i]);

		for (int i = 0; i < size - k; i++)
			temp.push_back(nums[i]);

		nums = temp;

	};

};