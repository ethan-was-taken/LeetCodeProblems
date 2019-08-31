#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

#include "stopper.h"

using namespace std;

class wiggleMaxSubsequence {
public:
	static int wiggleMaxLength(vector<int>& nums) {

		vector<int> up;
		vector<int> down;

		up.push_back(1);
		down.push_back(1);

		for (int i = 1; i < nums.size(); i++) {

			if (nums[i] > nums[i - 1]) {
				up.push_back(down[down.size() - 1] + 1);
				down.push_back(down.back());
			}
			else if (nums[i] < nums[i - 1]) {
				down.push_back(up[up.size() - 1] + 1);
				up.push_back(up.back());
			}

		}

		return max(up.back(), down.back());

	};
	
};