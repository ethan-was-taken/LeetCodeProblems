#pragma once
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class majorElement {
public:
	int majorityElement(vector<int>& nums) {

		unordered_map<int, int> instances;
		for (int curr : nums) {

			if (instances.find(curr) == instances.end()) {
				instances.insert(pair<int, int>(curr, 1));
			}
			else
				instances.find(curr)->second++;

			if (instances.find(curr)->second >= (nums.size / 2))
				return curr;

		}

		/*pair<int, int> largest = pair<int, int>(INT_MIN, INT_MIN);
		for (auto it : instances) {

			if (it.second > largest.second) {
				largest.first = it.first;
				largest.second = it.second;
			}

		}

		return largest.first;
		*/
		return 0;
	};

};