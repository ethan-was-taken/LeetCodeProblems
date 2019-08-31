#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class maxSubarray {
public:
	static int maxSubArray(vector<int>& nums) {

		int workingSum = 0;
		int maxi = INT_MIN;

		for (int i = 0; i < nums.size(); i++) {

			workingSum = (workingSum < 0) ? 0 : workingSum;

			workingSum += nums[i];
			maxi = max(maxi, workingSum);

			/*cout << "workingSum:\t" << workingSum << endl;
			cout << "maxi:\t" << maxi << endl;
			stopper::stop();*/

		}

		return maxi;

	};

};