#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "stopper.h"

using namespace std;

struct pair_compare {
	inline bool operator()(const pair<char, int> &first, const pair<char, int> &second) const {
		if (first.first == second.first)
			return first.second > second.second;
		return first.first < second.first;
	};
};

class maxSwap {
public:
	static int maximumSwap(int num) {

		string vals = to_string(num);
		pair<char, int> swapPos = findSwapPos(vals);
		
		char temp = vals.at(swapPos.first - 48);
		vals[swapPos.first - 48] = vals[swapPos.second];
		vals[swapPos.second] = temp;

		return stoi(vals);

	};

private:
	static pair<char, int> findSwapPos(string vals) {
		
		vector<pair<char, int>> copy = initializeCopy(vals);
		stable_sort(copy.rbegin(), copy.rend(), pair_compare());
		
		for (int i = 0; i < vals.size(); i++) {

			if (vals[i] != copy[i].first) {
				int j = findOtherSwapPos(vals, copy, i);
				return pair<char, int>(i + 48, copy[j].second);
			}	

		}

		return pair<char, int>(vals.size() - 1 + 48, copy[vals.size() - 1].second);

	};

	static vector<pair<char, int>> initializeCopy(string vals) {
		vector<pair<char, int>> copy;
		for (int i = 0; i < vals.size(); i++)
			copy.push_back(pair<char, int>(vals[i], i));
		return copy;
	};

	static int findOtherSwapPos(string vals, vector<pair<char, int>> copy, int i) {
		int j = i;
		while (j < vals.size() && copy[i].first == copy[j].first) { j++; }
		if (j != i) { j--; }
		return j;
	};

};