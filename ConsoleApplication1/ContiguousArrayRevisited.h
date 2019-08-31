#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class ContiguousArrayRevisited {
public:
	// O(nm); where
	//		n = size of nums
	//		m = maxSubarrayLength
	int findMaxLength(const vector<int> &nums) {

		vector<int> info(2, 0);
		for (auto curr : nums)
			info[curr]++;

		int maxSubarrayLength = min(info[0], info[1]) * 2;
		int length = maxSubarrayLength;
		for (; length >= 2; length -= 2) {
			if (hasValidSubarrayOfLength(nums, length))
				break;
		}

		return length;

	};

	int findMaxLengthFromSol(const vector<int> &nums) {

		int count = 0;
		int maxDelta = INT_MIN;
		// Count, first encounter's index of count, last encounter's index
		unordered_map<int, pair<int, int>> countsInfo;

		for (int i = 0; i < nums.size(); i++) {

			updateCount(nums, i, count);

			if (countsInfo[count].first == NULL)
				countsInfo[count].first = i;
			else {

				countsInfo[count].second = i;

				int currDelta = countsInfo[count].second - countsInfo[count].first;
				maxDelta = max(currDelta, maxDelta);

			}
		}

		return maxDelta;

	};

	int findMaxLengthBruteForce(vector<int> &nums) {

		int contiguousLength = 0;
		vector<int> info(2, 0);

		for (int i = 0; i < nums.size(); i++) {

			for (int j = i; j < nums.size(); j++) {
				
				int curr = nums[j];
				info[curr]++;

				if (info[0] == info[1])
					contiguousLength = max(contiguousLength, j - i + 1);

			}

			info[0] = 0;
			info[1] = 0;

		}

		return contiguousLength;

	};

private:
	inline bool hasValidSubarrayOfLength(const vector<int> &nums, const int &subarrayLength) const {

		// Setup
		vector<int> info(2, 0);
		for (int i = 0; i < subarrayLength; i++)
			info[nums[i]]++;

		int rptr = subarrayLength;
		for (int i = 0; rptr < nums.size(); i++, rptr++) {
			
			if (info[0] == info[1])
				return true;

			info[nums[i]]--;
			info[nums[rptr]]++;

		}

		return info[0] == info[1];

	};

	inline void updateCount(const vector<int> &nums, const int &i, int &count) {
		if (nums[i] == 1)
			count++;
		else
			count--;
	};

};