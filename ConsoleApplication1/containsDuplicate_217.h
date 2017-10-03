#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class containsDuplicate_217 {
public:
	bool containsDuplicate(vector<int>& nums) {

		unordered_map<int, int> numInstances;
		for (int i : nums) {

			numInstances[i]++;
			if (numInstances[i] >= 2)
				return true;

		}

		return false;

	};
};