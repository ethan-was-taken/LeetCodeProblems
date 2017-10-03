#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class houseRobber {
public:
	int rob(vector<int>& nums) {

		//~edge cases~
		if (nums.empty())
			return 0;
		if (nums.size() == 1)
			return nums[0];

		pair<int, int> curr;
		curr.first = nums[0];
		curr.second = 0;
		choices.push_back(curr);

		for (int i = 1; i < nums.size(); i++) {

			pair<int, int> curr;
			curr.first = robHouse(nums[i], i);
			curr.second = dontRobHouse(i);

			choices.push_back(curr);

		}

		return max(choices.back().first, choices.back().second);

	};

private:
	// More code, but easier to read IMO
	inline int robHouse(int amount, int index) {
		return choices[index - 1].second + amount;
	};

	inline int dontRobHouse(int index) {
		return max(choices[index - 1].first, choices[index - 1].second);
	};

	//Global Vars
	vector<pair<int, int>> choices;
};