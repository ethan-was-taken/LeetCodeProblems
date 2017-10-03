#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

struct pair_compare {
	inline bool operator()(const pair<char, int> &first, const pair<char, int> &second) const {
		return first.second < second.second;
	};
};

class sortByFrequency {
public:
	typedef priority_queue<pair<char, int>, vector<pair<char, int>>, pair_compare> pq;
	string frequencySort(string s) {

		unordered_map<char, int> frequency;
		for (char curr : s)
			frequency[curr]++;

		pq sorted;
		unordered_map<char, int>::iterator it = frequency.begin();
		for (; it != frequency.end(); it++)
			sorted.push(pair<char, int>(it->first, it->second));

		int i = 0;
		while (!sorted.empty()) {

			auto curr = sorted.top();
			sorted.pop();

			int upperBound = i + curr.second;
			char ch = curr.first;

			for (int j = i; j < upperBound; j++, i++)
				s[j] = ch;

		}

		return s;

	}

};