#pragma once
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class firstUniqueChar {
public:
	int firstUniqChar(string s) {
		// char -> #times in s -> first instance index
		unordered_map<char, pair<int, int>> chars;

		for (int i = 0; i < s.size(); i++) {

			char curr = s[i];

			if (chars.find(curr) == chars.end()) {
				pair<int, int> toAdd(1, i);
				chars.insert(pair<char, pair<int, int>>(curr, toAdd));
			}
			else
				chars.find(curr)->second.first++;


		}

		/*
		// My Solution
		for (char curr : s) {

			if (chars.find(curr)->second.first == 1)
				return chars.find(curr)->second.second;

		}
		
		return -1;
		*/

		// Faster Solution: https://discuss.leetcode.com/topic/55082/c-2-solutions
		int index = INT_MAX;
		for (auto curr : chars) {

			if (curr.second.first == 1)
				index = min(index, curr.second.second);

		}

		return (index == INT_MAX) ? -1 : index;

	};

};