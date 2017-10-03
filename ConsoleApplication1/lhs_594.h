#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class lhs_594 {
public:
	int findLHS(vector<int>& nums) {

		if (nums.empty())
			return 0;
		
		unordered_map<int, int> instances = getInstances(nums);
		
		int length = INT_MIN;
		for (auto it : instances) {
			
			int key = it.first;
			if (instances.find(it.first + 1) != instances.end())
				length = max(length, it.second + instances[it.first + 1]);			

		}

		cout << (length == INT_MIN ? 0 : length) << endl;

		return (length == INT_MIN) ? 0 : length;

	};

private:
	inline unordered_map<int, int> getInstances(vector<int>& nums) {

		unordered_map<int, int> instances;
		for (int i = 0; i < nums.size(); i++)
			instances[nums[i]]++;

		return instances;

	};

};