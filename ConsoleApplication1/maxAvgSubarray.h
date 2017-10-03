#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class maxAvgSubarray {
public:
	double findMaxAverage(vector<int>& nums, int k) {

		if (nums.size() < k)
			return -1;

		int lptr = 0;
		int rptr = 0;

		// Get sum set to the sum of the first k values
		int sum = 0;
		while (rptr < k)
			sum += nums[rptr++];

		double maxAvg = INT_MIN;
		while (rptr < nums.size()) {

			double avg = (double) sum / k;
			maxAvg = max(maxAvg, avg);

			sum -= nums[lptr];
			sum += nums[rptr];
			
			lptr++;
			rptr++;

		}

		maxAvg = max(maxAvg, (double)sum / k);

		return maxAvg;

	};

};