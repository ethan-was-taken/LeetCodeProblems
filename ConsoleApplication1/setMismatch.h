#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#include "printer.h"
#include "stopper.h"

using namespace std;

class setMismatch {
public:
	static vector<int> findErrorNums(vector<int>& nums) {

		int duplicate = INT_MIN;
		vector<int> instances(nums.size() + 1, 0);
		for (int curr : nums) {
			instances[curr]++;
			duplicate = instances[curr] == 2 ? curr : duplicate;
		}

		int missingNum = findMissingNum(instances);
		vector<int> toReturn = { duplicate, missingNum };

		return toReturn;

	};

private:
	static inline int findMissingNum(vector<int> &instances) {
		int missingNum = INT_MIN;
		for (int i = 1; i < instances.size(); i++) {
			if (instances[i] == 0) {
				missingNum = i;
				break;
			}
		}
		return missingNum;
	};
};