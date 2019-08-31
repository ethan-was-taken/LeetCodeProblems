#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

struct WordInterval {
	
	string word;
	pair<int, int> interval;

	WordInterval(string word, int start, int end) {
		this->word = word;
		interval = make_pair(start, end);
	};

	bool operator<(const WordInterval &word2) const {
		if (interval.first == word2.interval.first)
			return interval.second < word2.interval.second;
		return interval.first < word2.interval.first;
	};

};

struct WordIntervalComp {
	bool operator()(const int &left, const WordInterval &word) const {
		return left < word.interval.first;
	};
	bool operator()(const WordInterval &word, const int &right) const {
		return word.interval.first < right;
	};
};

class WordBreak {
public:
	bool wordBreak(string str, vector<string> &wordDict) {
		
		setup(str, wordDict);
		if(words.size() < 1000)
			findPath(0);

		return isSegmentable;

	};

private:
	multiset<WordInterval> words;
	string str;
	bool isSegmentable;

	void setup(string &str, vector<string> &wordDict) {

		this->str = str;
		isSegmentable = false;

		for (string curr : wordDict)
			addAllInstancesOf(curr);

	};

	void addAllInstancesOf(string &curr) {

		int startPos = str.find(curr);
		while (startPos != string::npos) {
			words.emplace(WordInterval(curr, startPos, startPos + curr.length() - 1));
			startPos = str.find(curr, startPos + 1);
		}

	}

	void findPath(int startIndex) {

		if (isSegmentable || startIndex >= str.size()) {
			isSegmentable = true;
			return;
		}

		auto range = equal_range(words.begin(), words.end(), startIndex, WordIntervalComp());
		for (auto i = range.first; i != range.second; i++)
			findPath(i->interval.second + 1);

	};

};