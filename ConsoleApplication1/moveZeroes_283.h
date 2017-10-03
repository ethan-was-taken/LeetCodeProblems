#pragma once
#include <iostream>
#include <vector>

using namespace std;

class moveZeroes_283 {
public:
	void moveZeroes(vector<int>& nums) {

		int lptr = setToIndexWithZero(nums);
		int rptr = lptr;

		for (; lptr < nums.size(); lptr++) {

			setToIndexWithNonZero(nums, rptr);

			if (rptr >= nums.size())
				break;

			nums[lptr] = nums[rptr];
			nums[rptr] = 0;
			rptr++;

		}

	};

private:
	inline int setToIndexWithZero(vector<int> nums) {

		int lptr = 0;
		while (lptr < nums.size() && nums[lptr] != 0)
			lptr++;

		return lptr;

	};

	inline void setToIndexWithNonZero(vector<int> nums, int &start) {

		while (start < nums.size() && nums[start] == 0)
			start++;

	};

};
/*
1.	increase lptr (and rptr) till we reach a 0
2.	increase rptr till it gets to a non-zero num OR end of vector
3.	if rptr at end of vector && rptr is pointing at a zero
		break
	else if rptr at  end 
		swap
		break
	else 
		swap
4.	Increase lptr
5.	loop to 2
6.	fill in rest of vector with 0's
		
*/