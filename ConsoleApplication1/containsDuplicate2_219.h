#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class containsDuplicate2_219 {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {

		unordered_multimap<int, int> numInstances;
		for (int i = 0; i < nums.size(); i++) {

			
			if (numInstances.find(nums[i]) != numInstances.end() && 
				hasNearbyDup(numInstances, nums[i], i, k)) {
				return true;
			}

			numInstances.insert(pair<int, int>(nums[i], i));

		}

		return false;

	};

private:
	typedef unordered_multimap<int, int>::iterator Iter;

	inline bool hasNearbyDup(unordered_multimap<int, int> &numInstances, int curr, int currIndex, int k) {

		pair<Iter, Iter> range = numInstances.equal_range(curr);
		Iter it = range.first;
		for (; it != range.second; it++) {

			int delta = abs(it->second - currIndex);
			if (delta <= k)
				return true;

		}

		return false;

	};

};