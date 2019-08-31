#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class PalindromeNumber {
public:
	bool isPalindrome(int x) {

		if (x < 0)
			return false;

		int backwardsNum = 0;
		int32_t tempNum = x;

		int exponent = (int)log10(x);
		int multiplier = (int) pow(10, exponent);
		for (int32_t i = multiplier; tempNum != 0; div10(i)) {
			backwardsNum += tempNum % 10 * i;
			div10(tempNum);
		}

		return backwardsNum == x;

	};

private:
	inline void div10(int32_t &dividend) {
		int64_t invDivisor = 0x1999999A;
		dividend = (int32_t)((invDivisor * dividend) >> 32);
	};

};