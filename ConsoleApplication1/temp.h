#pragma once
#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <bitset>
#include <string>
#include <queue>
#include <unordered_map>
#include <set>

#include "treeNode.h"
#include "stopper.h"

#define PAIR pair<string, int>

using namespace std;

struct StringIntPairComp {
	inline bool operator()(const PAIR &val1, const PAIR &val2) const {
		if (val1.second == val2.second)
			return val1.first < val2.first;
		return val1.second < val2.second;
	};
};

class TopKFrequentWords {
public:
	vector<string> topKFrequent(vector<string> &words, int k) {

		setFrequency(words);
		orderWordFrequency();
		setResult(k);

		return result;

	};

private:
	unordered_map<string, int> frequency;
	priority_queue<PAIR, vector<PAIR>, StringIntPairComp> queue;
	vector<string> result;

	void setFrequency(vector<string> &words) {
		for (int i = 0; i < words.size(); i++)
			frequency[words[i]]++;
	};

	void orderWordFrequency() {
		for (auto it : frequency)
			queue.emplace(it.first, it.second);
	};

	void setResult(int k) {
		for (int i = 0; i < k; i++) {
			PAIR curr = queue.top();
			result.push_back(curr.first);
			queue.pop();
		}
	};
};