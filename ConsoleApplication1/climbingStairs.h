#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class climbingStairs {
public:
	int climbStairs(int n) {

		if (n == 0)
			return 0;
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;

		// set up the memo
		vector<int> memo;
		memo.push_back(0);
		memo.push_back(1);
		memo.push_back(2);

		for (int i = 3; i <= n; i++)
			memo.push_back(memo[i - 1] + memo[i - 2]);
		
		return memo.back();
	};
};