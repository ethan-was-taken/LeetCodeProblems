#pragma once
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

//https://stackoverflow.com/questions/15160889/how-to-make-unordered-set-of-pairs-of-integers-in-c
struct pair_hash {
	inline std::size_t operator()(const std::pair<int, int> & v) const {
		return v.first * 31 + v.second;
	}
};

class subarraySum_560 {
public:
	int subarraySum(vector<int>& nums, int k) {
		/*
		if (nums.size() < 2)
			return nums[0] == k;

		int lptr = 0;
		int rptr = 1;
		int sum = nums[lptr] + nums[rptr];
		int toReturn = 0;
		while(lptr < nums.size()) {

			if (++rptr > nums.size()) {
				lptr++;
				rptr = lptr;
				sum = nums[lptr];
			}

			if (sum < k) {
				sum += nums[rptr];
				continue;
			}
			
			if (sum == k) {
				toReturn++;
				sum += nums[rptr];
				continue;
			}

			if (sum > k) {
				int sub = nums[lptr];
				lptr++;
				sum -= sub;
			}

		}
		*/

		unordered_set<pair<int, int>, pair_hash> ranges;
		for (int i = 0; i < nums.size(); i++) {

			int sum = 0;

			for (int j = i; j < nums.size(); j++) {

				sum += nums[j];
				
				if (sum == k) {
					ranges.insert(pair<int, int>(i, j));
				}

			}

			if (sum == k) {
				ranges.insert(pair<int, int>(i, nums.size() - 1));
			}

		}

		cout << "ranges" << endl;
		cout << "---------------" << endl;
		for (auto i : ranges) {
			cout << i.first << "\t" << i.second << endl;
		}

		return ranges.size();

	};

private:

};