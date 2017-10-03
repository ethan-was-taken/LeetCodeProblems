#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class summaryRanges_228 {
public:
	vector<string> summaryRanges(vector<int>& nums) {

		// Sanity check
		if (nums.empty())
			return vector<string>();

		nums.push_back(nums.back() - nums.back() * 11);

		vector<string> toReturn;
		int start = nums[0];
		int end = start;

		for (int i = 1; i < nums.size(); i++) {

			end = nums[i - 1];

			if (nums[i - 1] == nums[i] - 1)
				continue;

			string temp;
			if (start != end)
				temp = to_string(start) + "->" + to_string(end);
			else
				temp = to_string(start);

			toReturn.push_back(temp);

			start = nums[i];
			end = start;

		}

		return toReturn;

	};

};