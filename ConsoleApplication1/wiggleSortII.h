#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class wiggleSortII {
public:
	void wiggleSort(vector<int>& nums) {

		vector<int> sorted = nums;
		sort(sorted.begin(), sorted.end());

		int size = nums.size() - 1;

		int j = size;
		int i = size / 2;
		int numsIndex = 0;

		while (i >= 0) {

			cout << "i:\t" << i << endl;
			cout << "j:\t" << j << endl;
			cout << "numsIndex:\t" << numsIndex << endl;

			if (numsIndex < nums.size())
				nums[numsIndex++] = sorted[i];
			if (numsIndex < nums.size())
				nums[numsIndex++] = sorted[j];

			j--;
			i--;

		}

		for (int i : nums) {
			cout << i << setw(3);
		}

		check(nums);
		
	}

private:
	inline void check(vector<int>& nums) {

		for (int i = 1; i < nums.size(); i++) {

			if (i % 2 != 0 && nums[i - 1] >= nums[i]) {
				cout << endl;
				cout << "wrong ans! " << endl << nums[i - 1] << " is >= " << nums[i] << endl;
				return;
			}
			else if(i % 2 == 0 && nums[i - 1] <= nums[i]) {
				cout << endl;
				cout << "wrong ans! " << endl << nums[i - 1] << " is <= " << nums[i] << endl;
				return;
			}
			
		}
		cout << endl;
		cout << "correct" << endl;

	}

};