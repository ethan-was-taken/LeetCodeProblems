#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>

#include "stopper.h"


using namespace std;

class singleNum {
public:
	static int fukkk(vector<int> nums) {

		unordered_map<int, int> instances;
		for (int i = 0; i < nums.size(); i++)
			instances[nums[i]]++;
		
		for (auto curr : instances) {
			if (curr.second == 1)
				return curr.first;
		}

		return -1;

	}
};