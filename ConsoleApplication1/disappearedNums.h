#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class disappearedNums {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {

		vector<int> ans(nums.size() + 1, 0);
		for (auto curr : nums) {
			ans[curr] = curr;
		}

		int originalSize = ans.size();
		for (int i = 1; i < originalSize; i++) {
			
			if (ans[i] == 0)
				ans.push_back(i);

		}

		ans.erase(ans.begin(), ans.begin() + originalSize);

		return ans;

	};

};