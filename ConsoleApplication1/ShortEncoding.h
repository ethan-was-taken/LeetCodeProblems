#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct TrieNode {
	
	unordered_map<char, TrieNode*> neighbors;

	inline bool contains(const char &currLetter) {
		if (this == nullptr)
			return false;
		return neighbors.find(currLetter) != neighbors.end();
	};

};

class ShortEncoding {
public:
	int minimumLengthEncoding(vector<string> &words) {

		setup(words);

		for (string currWord : words) {

			bool updateResult = insert(currWord);
			if (updateResult)
				result.append(currWord + "#");

		}

		return result.size();

	};

private:
	TrieNode* root;
	string result;

	void setup(vector<string> &words) {

		sort(words.begin(), words.end(),
			[](const string &str1, const string &str2) {
				if (str1.size() == str2.size())
					return str1 > str2;
				return str1.size() > str2.size();
			}
		);

		root = new TrieNode;

	};

	inline bool insert(const string &currWord) {

		TrieNode* curr = root;
		bool updateResult = false;

		for (int i = currWord.size() - 1; i >= 0; i--) {

			char currLetter = currWord[i];
			if (!curr->contains(currLetter)) {
				curr->neighbors[currLetter] = new TrieNode;
				updateResult = true;
			}

			curr = curr->neighbors[currLetter];

		}

		return updateResult;

	};

};