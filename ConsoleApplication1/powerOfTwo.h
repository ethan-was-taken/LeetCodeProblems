#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

class powerOfTwo {
public:
	bool isPowerOfTwo(int n) {
		
		if (n == 0)
			return false;

		double ans = log2(n);

		return floor(ans) == ans;

	}

};