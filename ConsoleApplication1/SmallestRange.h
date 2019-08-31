#pragma once
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <unordered_set>

#define CUST_ITERATOR map<int, unordered_set<int>>::iterator

using namespace std;

class SmallestRange {
public:
	vector<int> smallestRange(vector<vector<int>> &nums) {

		setup(nums);
	
		for (CUST_ITERATOR lptr = this->numsTotal.begin(); lptr != this->numsTotal.end(); lptr++) {

			CUST_ITERATOR rptr = getPtrToEndOfRange(nums, lptr);
			// It's possible the rptr just points to the end of the list
			if (!hasFoundRange(nums))
				continue;			

			if (setResultRange(lptr, rptr) == 0)
				break;

			vectorsInRange.clear();

		}

		return resultRange;

	};
	
private:
	map<int, unordered_set<int>> numsTotal;
	unordered_set<int> vectorsInRange;
	vector<int> resultRange;

	inline void setup(vector<vector<int>> &nums) {

		resultRange.push_back(0);
		resultRange.push_back(INT_MAX);

		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < nums[i].size(); j++)
				numsTotal[nums[i][j]].insert(i);
		}

	};

	inline CUST_ITERATOR getPtrToEndOfRange(vector<vector<int>> &nums, CUST_ITERATOR &lptr) {
		CUST_ITERATOR rptr = lptr;
		for (; rptr != this->numsTotal.end() && !hasFoundRange(nums); rptr++) {
			for (auto vectorsWithValue : rptr->second)
				vectorsInRange.insert(vectorsWithValue);
		}
		rptr--;
		return rptr;
	};

	inline bool hasFoundRange(vector<vector<int>> &nums) {
		return vectorsInRange.size() == nums.size();
	};

	inline int setResultRange(CUST_ITERATOR &lptr, CUST_ITERATOR &rptr) {
		int resultDelta = resultRange[1] - resultRange[0];
		int currDelta = rptr->first - lptr->first;
		if (currDelta < resultDelta) {
			resultRange[0] = lptr->first;
			resultRange[1] = rptr->first;
		}
		return currDelta;
	};

};