#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>

#define INT_SIZE 32

using namespace std;

//subsets_78
class subsets_78 {
public:
	vector<vector<int>> subsets(vector<int>& nums) {

		vector<vector<int>> ans;

		if (nums.size() > INT_SIZE)
			return ans;

		double powerSetSize = pow(2, nums.size());

		for (int i = 0; i < powerSetSize; i++) {

			vector<int> currSubset;

			bitset<INT_SIZE> count(i);
			addToSubset(count, currSubset, nums);

			ans.push_back(currSubset);

		}

		return ans;
	};

private:
	inline void addToSubset(bitset<INT_SIZE> count, vector<int> &subset, vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			if (count[i] == 1) 
				subset.push_back(nums[i]);
		}
	};
	
};