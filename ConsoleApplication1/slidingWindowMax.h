#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;


class slidingWindowMax {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {

		/*
		Algo:
		-----------
		1.	Add the first k elements to a deque
			1.1		While doing so, keep track of the largest value

		2.	for 0 -> nums.size() - k

			2.1		when you slide the window remove the first element, and add the new element to the back; While doing this:
				2.2	    if the new value added > max
							set max value

			2.3		if you remove the largest value
						recompute the max value by "iterating" through the deque
					
			2.4		add the curr max to the vector that will be returned

		*/

		if (nums.empty())
			return nums;

		int maxi = INT_MIN;
		deque<int> window;
		vector<int> maxValues;

		for (int i = 0; i < k; i++) {					// 1
			window.push_back(nums[i]);
			maxi = max(maxi, nums[i]);					// 1.1
		}

		maxValues.push_back(maxi);

		for (int i = 0; i < nums.size() - k; i++) {		// 2

			int popped = window.front();

			window.pop_front();							// 2.1
			window.push_back(nums[i + k]);

			maxi = max(nums[i + k], maxi);				// 2.2

			if (popped == maxi) {						// 2.3
				maxi = recomputeMax(window);
			}

			maxValues.push_back(maxi);					// 2.4

		}

		return maxValues;

	};

private:
	inline int recomputeMax(deque<int> window) {

		int maxi = INT_MIN;
		while (!window.empty()) {

			int curr = window.front();
			window.pop_front();

			maxi = max(curr, maxi);

		}

		return maxi;

	};

};