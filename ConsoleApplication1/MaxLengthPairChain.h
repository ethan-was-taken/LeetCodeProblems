#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include <algorithm>
#include <random>

#include "printer.h"

#define INVALID -1

using namespace std;

class MaxLengthPairChain {
public:
	int findLongestChain(vector<vector<int>> &_pairs) {

		if (_pairs.size() <= 1)
			return _pairs.size();

		setup(_pairs);

		int maxChainLength = INT_MIN;
		for (auto currIter = pairs.rbegin(); currIter != pairs.rend(); currIter++) {

			vector<int> currVec = *currIter;
			int stoppingPoint = (currIter + 1) == pairs.rend() ? currVec.front() : (*(currIter + 1)).front();

			int chainLength = getChainLength(currVec.back() + 1);
			maxChainLength = max(maxChainLength, chainLength);
			addChainLengthToDP(currVec, chainLength, stoppingPoint);
						
		}

		return maxChainLength;

	};


private:
	vector<vector<int>> pairs;
	vector<int> dp;

	void setup(vector<vector<int>> &_pairs) {
		
		pairs = _pairs;
		this->sort(pairs);

		vector<int> _dp(pairs.back()[0] + 1, INVALID);
		dp = _dp;

	};

	void sort(vector<vector<int>> &pairs) {
		std::sort(pairs.begin(), pairs.end(), 
			[](const vector<int> one, const vector<int> two) {
				if (one.front() == two.front())
					return one.back() < two.back();
				return one.front() < two.front();
			}
		);
	};

	inline int getChainLength(const int nextInChain) {
		
		if (nextInChain > dp.size() - 1)
			return 1;

		return dp[nextInChain] + 1;

	};

	inline void addChainLengthToDP(vector<int> &currVec, int chainLength, int stoppingPoint) {
		
		// If the current chainLength < the stored chainLength; don't update dp
		if (chainLength < dp[currVec[0]])
			return;

		// Populate DP[i] with chainLength until we get to (up to & including) stoppingPoint + 1
		dp[currVec[0]] = chainLength;
		for (int i = currVec[0] - 1; i > stoppingPoint && i >= 0; i--)
			dp[i] = chainLength;

	};

};