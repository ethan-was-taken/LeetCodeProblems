#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class NonDecreasingArray {
public:
	bool checkPossibility(vector<int> &nums) {

		// Sanity check
		if (nums.size() <= 1)
			return true;

		vector<int> minVals = nums;
		//minVals.back() = minVals[minVals.size() - 2];
		for (int i = (int) nums.size() - 2; i >= 0; i--)
			minVals[i] = min(nums[i + 1], minVals[i + 1]);
		
		for (auto curr : minVals)
			cout << curr << " ";
		cout << endl;

		int numMods = 0;
		for (int i = 0; i < nums.size(); i++) {

			// Doesn't handle drop at back of array;
			// e.g. 1, 1, 0
			if (nums[i] > minVals[i]) {
				numMods++;
				nums[i] = minVals[i];
			}

		}

		return 0;

	};

private:

};