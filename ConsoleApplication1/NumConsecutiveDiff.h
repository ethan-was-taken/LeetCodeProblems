#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <algorithm>
#include <random>

using namespace std;

struct storage {
public:
	storage() {
		vector<map<int, set<int>>> temp(10, map<int, set<int>>());
		vals = temp;
	};

	void push_back(int toAdd, int toAddSize) {
		push_back(toAdd, getStartingNum(toAdd), toAddSize);
	};

	void push_back(int toAdd, int startsWith, int toAddSize) {
		vals[startsWith][toAddSize].emplace(toAdd);
	};

	set<int> getNumsStartingWithXofSizeY(int begVal, int size) {
		auto numsStartingWith = getNumsStartingWith(begVal);
		return numsStartingWith[size];
	};

	map<int, set<int>> getNumsStartingWith(int begVal) {
		return vals[begVal];
	};

private:
	vector<map<int, set<int>>> vals;

	int getStartingNum(int in) {
		int prev = 0;
		while (in != 0) {
			prev = in;
			in = in % 10;
		}
		return prev;
	};

};

class NumConsectiveDiff {
public:
	vector<int> numsSameConsecDiff(int digitLength, int delta) {

		// Handle special cases
		if (digitLength <= 1) {
			if (digitLength == 1) res = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			return res;
		}

		setup(digitLength, delta);

		string starter = "";
		for (int currDigit = 1; currDigit < 10; currDigit++) {
			starter.push_back(intToChar(currDigit));
			dfs(starter, currDigit);
			starter.pop_back();
		}

		return res;

	};

private:
	vector<int> res;
	int targetDigitLength;
	int delta;

	void setup(int digitLength, int delta) {
		targetDigitLength = digitLength;
		this->delta = delta;
	};

	inline char intToChar(int input) {
		return input + '0';
	};

	void dfs(string &currNum, int prevAdded) {

		// base case check here
		if (currNum.size() == targetDigitLength) {
			res.push_back(stoi(currNum));
			return;
		}

		// Go "left"
		int valToAppend = prevAdded - delta;
		if (valToAppend >= 0) {
			currNum.append(to_string(valToAppend));
			dfs(currNum, valToAppend);
			currNum.pop_back();
		}

		// Go "right"
		valToAppend = prevAdded + delta;
		if (valToAppend <= 9) {
			currNum.append(to_string(valToAppend));
			dfs(currNum, valToAppend);
			currNum.pop_back();
		}

	};

};