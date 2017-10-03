#pragma once
#include <iostream>
#include <math.h>
#include <limits>

#define MAX 1162261467 

using namespace std;

class powerOfThree {
public:
	bool isPowerOfThree(int n) {

		if (n < 0)
			return false;

		return MAX % n == 0;

	};

};