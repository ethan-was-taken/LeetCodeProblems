#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class sumClosest {
public:
	/*
	1.	sort array -> O(nlogn)

	2.	iterate though array, then once more starting from 
		next value -> O(n^2)

	3.	Add the two nums and subtract result from target
			
	4.	Binary Search for next value
			if you find the exact value 
				return it
			otherwise 
				look left and right to find closest value to target 
				store it
	5.	loop
	*/
	int threeSumClosest(vector<int>& nums, int target) {

		if (nums.size() == 3) {
			int res = 0;
			for (int i : nums) {
				res += i;
			}
			return res;
		}

		sort(nums.begin(), nums.end());

		//int ans = binarySearch(nums, 0, nums.size() - 1, target);
		//cout << nums[ans] << endl;

		int res = INT_MAX;

		for (int i = 0; i < nums.size() - 1; i++) {

			for (int j = i + 1; j < nums.size(); j++) {

				vector<int> temp = nums;
				temp.erase(temp.begin() + i);
				temp.erase(temp.begin() + j - 1);

				int lookForVal = (nums[i] + nums[j]) * -1 + target;

				cout << "nums[i]:\t" << nums[i] << endl;
				cout << "nums[j]:\t" << nums[j] << endl;

				int closestVal = binarySearch(temp, 0, temp.size() - 1, lookForVal);

				int delta1 = abs((closestVal + nums[i] + nums[j]) - target);
				int delta2 = abs(res - target);
				int mini = min(delta1, delta2);

				cout << "closest Val:\t" << closestVal << endl;
				cout << "d1:\t" << delta1 << endl;
				cout << "d2:\t" << delta2 << endl;
				cout << "mini:\t" << mini << endl;

				if (delta1 == 0 || delta2 == 0) {
					return target;
				}

				if (mini == delta1) {
					res = closestVal + nums[i] + nums[j];
				}

				if (res == INT_MIN || res == INT_MAX)
					res = delta1;
				

				cout << "res:\t" << res << endl;
				cout << "--------------------" << endl << endl;

			}

		}

		return res;

	};

private:
	inline int binarySearch(vector<int>& nums, int lptr, int rptr, int target) {

		int mptr = (rptr - lptr) / 2 + lptr;

		if (nums[mptr] == target) {
			return nums[mptr];
		}

		print(nums[lptr], nums[mptr], nums[rptr], target);

		if (lptr < rptr) {

			if (nums[mptr] < target) {
				return binarySearch(nums, mptr + 1, rptr, target);
			}
			else {
				return binarySearch(nums, lptr, mptr - 1, target);
			}

		}

		int delta1 = (mptr - 1 < nums.size()) ? abs(nums[mptr - 1] - target) : INT_MAX;
		int delta2 = abs(nums[mptr] - target);
		int delta3 = (mptr + 1 < nums.size()) ? abs(nums[mptr + 1] - target) : INT_MAX;

		int mini = min(min(delta1, delta2), delta3);

		
		/*
		cout << "d1:\t" << delta1 << "\t->\t" << mptr - 1 << endl;
		cout << "d2:\t" << delta2 << "\t->\t" << mptr  << endl;
		cout << "d3:\t" << delta3 << "\t->\t" << mptr + 1 << endl;
		cout << "mini:\t" << mini << endl;
		*/
		

		if (mini == delta1) {
			//cout << "mini == d1" << endl;
			cout << "1 returning:\t" << mptr - 1 << endl;
			return nums[mptr - 1];
		}
		else if (mini == delta2) {
			//cout << "mini == d2" << endl;
			cout << "2 returning:\t" << mptr << endl;
			return nums[mptr];
		}
		//cout << "mini == d3" << endl;
		cout << "3 returning:\t" << mptr + 1 << endl;
		return nums[mptr + 1];


	};

	void print(int l, int m, int r, int t) {
		cout << "target:\t" << t << endl;
		cout << "left:\t" << l << endl;
		cout << "mid:\t" << m << endl;
		cout << "right:\t" << r << endl;

		int stop; 
		cout << "\t\t\t\t\t";
		cin >> stop;

	};

}; 