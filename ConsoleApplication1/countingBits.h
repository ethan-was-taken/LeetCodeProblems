#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

class countingBits {
public:
	vector<int> countBits(int num) {

		// the starting off point
		memo.push_back(0);
		/*memo.push_back(1);
		memo.push_back(1);
		memo.push_back(2);*/

		int exponent = 1;
		int numBitsIndex = 0;

		for (int i = 1; i <= num; i++) {

			if (i >= pow(2, exponent)) {
				exponent++;
				numBitsIndex = 0;
			}

			memo.push_back(1 + memo[numBitsIndex]);
			numBitsIndex++;

		}

		check();

		return memo;

	};

private:
	void check() {

		bool set = false;

		for (int i = 0; i < memo.size(); i++) {

			cout << i << ":\t" << memo[i] << endl;

			bitset<8> curr(i);
			if (memo[i] != curr.count()) {
				cout << "num bits for " << i << " is wrong!" << endl;
				cout << "memo[" << i << "] is: " << memo[i] << endl;
				cout << "it should be: " << curr.count() << endl;
				set = true;
			}

		}
		if (!set)
			cout << "its all good!" << endl;

	};

	vector<int> memo;
};