#pragma once
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <vector>

#define INVALID_INDEX -1

using namespace std;

class CharIndexer {
public:
	CharIndexer(const string &input) {
		for (int i = 0; i < input.size(); i++)
			insert(input[i], i);
	};

	void insert(char key, int index) {
		storage[key].emplace(index);
	};

	bool containsKeyAfterIndex(char key, int index) {
		return getKeyIndexAfter(key, index) != INVALID_INDEX;
	};

	int getKeyIndexAfter(char key, int index) {
		
		if (storage.find(key) == storage.end())
			return INVALID_INDEX;

		set<int>* keySet = &(*storage.find(key)).second;
		set<int>::iterator res = upper_bound(keySet->begin(), keySet->end(), index);

		return res != keySet->end() ? *res : INVALID_INDEX;

	};

private:
	// char =		key; is a letter in the input string
	// set<int> =	value; are ordered indicies
	unordered_map<char, set<int>> storage;

};

class NumMatchingSubsequences {
public:
	int numMatchingSubseq(string input, vector<string> &words) {

		CharIndexer indexer(input);
		int result = 0;

		for (string word : words) {

			int prevCharIndex = INVALID_INDEX;
			int currCharIndex = INVALID_INDEX;

			for (char currChar : word) {
				
				currCharIndex = indexer.getKeyIndexAfter(currChar, prevCharIndex);
				if (currCharIndex == INVALID_INDEX)
					break;				

				prevCharIndex = currCharIndex;

			}

			if (currCharIndex != INVALID_INDEX)
				result++;

		}

		return result;

	};

private:

};