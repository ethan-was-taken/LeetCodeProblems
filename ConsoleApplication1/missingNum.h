#pragma once
#include <iostream>
#include <vector>

using namespace std;

class missingNum {
public:
	int missingNumber(vector<int>& nums) {

		vector<bool> sorted(nums.size(), false);

		for (int curr : nums) {
			sorted[curr] = true;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (!sorted[i])
				return i;
		}

		return nums.size();

	};

private:

};