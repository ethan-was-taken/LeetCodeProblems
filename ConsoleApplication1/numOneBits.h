#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

class numOneBits {
public:
	int hammingWeight(uint32_t n) {
		
		bitset<32> bits(n);

		return bits.count();

	};
};