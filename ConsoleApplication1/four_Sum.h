#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#include "stopper.h"
#include "printer.h"


#define DEBUG 1

using namespace std;

class four_sum {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {

		vector<vector<int>> ans;

		sort(nums.begin(), nums.end());

		for (auto curr : nums)
			numInstances[curr]++;
		
		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {

			sum += nums[i];
			numInstances[nums[i]]--;

			for (int j = i + 1; j < nums.size(); j++) {

				sum += nums[j];
				numInstances[nums[j]]--;

				for (int k = j + 1; k < nums.size(); k++) {

					sum += nums[k];
					numInstances[nums[k]]--;

					int toFind = target - sum;
#if DEBUG
					cout << "~~~~LoopThree~~~~" << endl;
					printer::print(numInstances);
					cout << "sum:\t" << sum << endl << endl;
					cout << "nums[i]:\t" << nums[i] << endl;
					cout << "nums[j]:\t" << nums[j] << endl;
					cout << "nums[k]:\t" << nums[k] << endl;
					cout << "toFind:\t" << toFind << endl;
					stopper::stop();
#endif

					if (numInstances[toFind] > 0) {
#if DEBUG
						cout << "adding" << endl;
						stopper::stop();
#endif
						vector<int> toAdd = { nums[i], nums[j], nums[k], toFind };
						ans.push_back(toAdd);
						sum -= nums[k];
						numInstances[nums[k]]++;
						break;
					}

					numInstances[nums[k]]++;
					sum -= nums[k];

				}

				numInstances[nums[j]]--;
				sum -= nums[j];

			}
			
			numInstances[nums[i]]--;
			sum = 0;

		}

		return ans;

	};

private:
	void innerTwoLoops(vector<int> &nums, int jIndex, int &sum, int target) {



	}

	unordered_map<int, int> numInstances;
};