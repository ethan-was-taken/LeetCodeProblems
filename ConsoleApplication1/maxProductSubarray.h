#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class maxProductSubarray {
public:
	int maxProduct(vector<int>& nums) {

		if (nums.size() == 1)
			return nums[0];

		int lptr = getNextNonZeroIndex(nums, -1);
		int rptr = lptr;
		int maxProd = INT_MIN;
		hasZero = false;

		while (rptr < nums.size()) {

			int numNegatives = 0;
			int firstNegIndex = INT_MIN;
			int lastNegIndex = INT_MIN;
			int currProd = 1;
			int firstSubProd = 1;

			while (rptr < nums.size() && nums[rptr] != 0) {

				numNegatives = (nums[rptr] < 0) ? numNegatives + 1 : numNegatives;

				if (firstNegIndex == INT_MIN) {

					firstSubProd *= nums[rptr];

					if (nums[rptr] < 0)
						firstNegIndex = rptr;

				}

				if (nums[rptr] < 0)
					lastNegIndex = rptr;

				currProd *= nums[rptr];
				rptr++;

			}

			// Dont want rptr pointing to a 0; we want it pointing to the value before the 0
			rptr = (rptr - 1 >= 0) ? rptr - 1 : 0;

			if (numNegatives % 2 == 0 || (lptr == rptr && firstNegIndex == lastNegIndex))
				maxProd = max(maxProd, currProd);
			else {

				int prod1 = currProd / firstSubProd;
				int prod2 = currProd / getLastSubProd(nums, lastNegIndex, rptr);
				maxProd = max(max(prod1, prod2), maxProd);

			}

			rptr = getNextNonZeroIndex(nums, rptr);
			lptr = rptr;

		}

		return (maxProd < 0 && hasZero) ? 0 : maxProd;

	};

private:
	inline int getNextNonZeroIndex(vector<int>& nums, int ptr) {

		// Increase rptr by 1 because its pointing to the value before the 0
		ptr++;
		while (ptr < nums.size() && nums[ptr] == 0) {
			hasZero = true;
			ptr++;
		}

		return ptr;

	};

	inline int getLastSubProd(vector<int>& nums, int start, int end) {

		int lastSubProd = 1;
		for (int i = start; i <= end; i++)
			lastSubProd *= nums[i];

		return lastSubProd;

	};

	//-----Global Vars-----
	bool hasZero;

};