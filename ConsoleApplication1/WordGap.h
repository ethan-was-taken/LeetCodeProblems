#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

class WordGap {
public:
	int maximumGap(vector<int> &nums) {

		if (nums.size() < 2)
			return 0;

		// O(nlogn) but removes all duplicates
		auto sorted = sort(nums);

		int maxDelta = 0;
		for (int i = 0; i < sorted.size() - 1; i++)
			maxDelta = max(maxDelta, (sorted[i + 1] - sorted[i]));

		return maxDelta;

	};

private:
	inline vector<int> sort(vector<int> &nums) {

		set<int> temp;
		for (auto curr : nums)
			temp.emplace(curr);

		vector<int> sorted;
		for (auto curr : temp)
			sorted.push_back(curr);

		return sorted;

	}
};