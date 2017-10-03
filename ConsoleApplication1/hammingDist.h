#pragma once
#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;

class hammingDist {
public:
	int hammingDistance(int x, int y) {

		bitset<32> first(x);
		bitset<32> second(y);
		bitset<32> ans = first ^ second;

		return ans.count();

	};


};