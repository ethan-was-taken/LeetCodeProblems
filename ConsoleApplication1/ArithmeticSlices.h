#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include <algorithm>
#include <random>

#include "printer.h"

#define SLICE_LENGTH 3
#define INVALID_DELTA -1

using namespace std;

class ArithmeticSlices {
public:
	int numberOfArithmeticSlices(vector<int> &_nums) {
		
		if (_nums.size() < SLICE_LENGTH)
			return 0;

		this->nums = std::move(_nums);
		setDeltas();
		res = 0;

		for (int i = 0; i < nums.size(); i++) {
			int length = findSliceLength(i);
			setupDpArray(length);
		}

		for (auto currVal : dp) {
			if (currVal >= SLICE_LENGTH)
				res += abs(currVal - SLICE_LENGTH + 1);
		}

		return res;

	};

private:
	vector<int> nums;
	vector<int> deltaWithPrev;
	vector<int> deltaWithNext;
	vector<int> dp;
	int res = 0;

	void setDeltas() {

		for (int i = 0; i < nums.size(); i++) {

			int prev = i == 0 ? INVALID_DELTA : abs(nums[i - 1] - nums[i]);
			int next = i >= nums.size() - 1 ? deltaWithNext.back() : abs(nums[i] - nums[i + 1]);

			deltaWithPrev.push_back(prev);
			deltaWithNext.push_back(next);

		}

		deltaWithPrev.push_back(deltaWithPrev.back());
		deltaWithNext.push_back(INVALID_DELTA);

	};

	int findSliceLength(int &i) {

		vector<int> currSlice;
		for (; i < nums.size(); i++) {

			if (isValidSlice(i))
				currSlice.push_back(nums[i]);
			else if (isEndOfSlice(i)) {

				currSlice.push_back(nums[i]);
				if (i < nums.size() - 1)
					currSlice.push_back(nums[i + 1]);

				break;

			}

		}

		return currSlice.size();

	}

	void setupDpArray(int sliceLength) {
		for (int i = sliceLength; i > 1; i--)
			dp.push_back(i);
	};

	inline bool isValidSlice(int i) {
		return deltaWithNext[i] == deltaWithNext[i + 1];
	};

	inline bool isEndOfSlice(int i) {
		return deltaWithNext[i] == deltaWithPrev[i + 1];
	};

};