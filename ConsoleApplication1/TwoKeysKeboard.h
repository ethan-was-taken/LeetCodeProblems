#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

#define INVALID -1

class TwoKeysKeboard {
public:
	int minSteps(int target) {

		setup(target);

		for (int i = 3; i <= target; i++) {

			if (isEven(i))
				memo[i] = calculateEvenMinSteps(i);
			else
				memo[i] = calculateOddMinSteps(i);

		}

		return memo[target];
	};

private:
	vector<int> memo;

	void setup(int target) {

		// Otherwise we crash @ memo[0] = INVALID section
		target = (target <= 2) ? 2 : target;

		vector<int> temp(target + 1, INVALID);
		memo = temp;

		memo[0] = INVALID;
		memo[1] = 0;
		memo[2] = 2;

	};

	inline bool isEven(int input) {
		return input % 2 == 0;
	};

	inline int calculateEvenMinSteps(int input) {
		return memo[input / 2] + 2;		// Add 2 because copy + paste
	};

	inline int calculateOddMinSteps(int input) {

		int largestDivisor = getLargestDivisor(input);
		int numExtraSteps = (input / largestDivisor);

		return isPrime(largestDivisor) ? input : memo[largestDivisor] + numExtraSteps;

	};

	inline int getLargestDivisor(int input) {

		for (int i = input / 2; i >= 2; i--) {
			if (input % i == 0)
				return i;
		}

		return 1;

	};

	inline bool isPrime(int largestDivisor) {
		return largestDivisor == 1;
	};


};