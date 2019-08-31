#pragma once
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

#define BASE_NEST_LENGTH 0
#define UNINITIALIZED -1

using namespace std;

class ArrayNesting {
public:
	int arrayNesting(vector<int>& nums) {

		longestPathLength = 0;

		for (int i = 0; i < nums.size(); i++) 
			getNestingLength(nums, i, BASE_NEST_LENGTH);

		return longestPathLength;

	};

private:
	unordered_set<int> visitedOnPath;
	int longestPathLength;

	void getNestingLength(vector<int>& nums, int index, int currLength) {

		if (hasVisitedIndex(index)) {
			setNestingLength(currLength);
			return;
		}

		visitedOnPath.insert(index);

		getNestingLength(nums, nums[index], currLength + 1);

	};

	inline bool hasVisitedIndex(int index) {
		return visitedOnPath.find(index) != visitedOnPath.end();
	};

	inline void setNestingLength(int nestingLength) {
		longestPathLength = max(nestingLength, longestPathLength);
	};

};