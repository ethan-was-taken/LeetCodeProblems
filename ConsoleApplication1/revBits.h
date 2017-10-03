#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <bitset>        

using namespace std;

class revBits {
public:
	uint32_t reverseBits(uint32_t n) {

		bitset<32> binary(n);
		bitset<32> rev;

		int j = 31;
		for (int i = 0; i < 32; i++)
			rev[i] = binary[j--];
		
		unsigned long long ans = rev.to_ullong();

		/*
		if (ans > INT_MAX)
			return INT_MAX;
		else if (ans < INT_MIN)
			return INT_MIN;
		*/
		return (uint32_t) ans;
	};
};