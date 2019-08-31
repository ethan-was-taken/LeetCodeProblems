#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

class LongestLengthFibSubSequence {
public:
	int lenLongestFibSubseq(vector<int> &input) {

		generateFibSequence(input.back());
		
		// setup hashtable
		for (int curr : input)
			instances[curr]++;

		for (auto iter = fibSequence.rend(); iter != fibSequence.rbegin(); iter++) {



		}

		return  0;

	};

private:
	vector<int> fibSequence;
	vector<int> dp;
	map<int, int> instances;		// first = number
									// second = num instances of number

	void generateFibSequence(int upperBound) {

		fibSequence.push_back(1);
		fibSequence.push_back(1);

		while(fibSequence.back() <= upperBound) {
			
			int prev = fibSequence[fibSequence.size() - 1];
			int prevPrev = fibSequence[fibSequence.size() - 2];

			fibSequence.push_back(prev + prevPrev);

		}

	};

};