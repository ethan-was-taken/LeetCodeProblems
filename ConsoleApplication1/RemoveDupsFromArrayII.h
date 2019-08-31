#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include <algorithm>
#include <random>

#define NUM_DUPS_ALLOWED 2

using namespace std;

class RemoveDupsFromArrayII {
public:
	int removeDuplicates(vector<int> &nums) {
		
		newSize = nums.size();
		for (lptr = 0; lptr < nums.size(); lptr++) {

			rptr = lptr;
			setExtraDuplicatesInVector(nums);
			lptr = --rptr;

		}

		sort(nums.begin(), nums.end());

		return newSize;

	};

private:
	int newSize;
	int lptr;
	int rptr;

	inline void setExtraDuplicatesInVector(vector<int> &nums) {

		int numDups = 0;		
		for (; rptr < nums.size() && nums[lptr] == nums[rptr]; rptr++) {

			numDups++;
			if (numDups > NUM_DUPS_ALLOWED) {
				nums[rptr] = INT_MAX;
				newSize--;
			}

		}
	}

};
