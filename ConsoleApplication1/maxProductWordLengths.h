#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>


using namespace std;

struct stringCompare {
	inline bool operator()(const string &first, const string &second) {
		return first.size() < second.size();
	};
};

class maxProductWordLengths {
public:
	int maxProduct(vector<string>& words) {

		//sort(words.rbegin(), words.rend(), stringCompare());

		int maxProd = 0;

		for (int i = 0; i < words.size(); i++) {

			unordered_set<char> chars = add(words[i]);

			for (int j = i + 1; j < words.size(); j++) {

				if (containsDups(chars, words[i], words[j])) 
					continue;
				
				int currProd = words[i].size() * words[j].size();
				maxProd = max(maxProd, currProd);
			}

		}

		return maxProd;

	};

private:
	inline unordered_set<char> add(string first) {

		unordered_set<char> chars;

		for (char c : first) {
			chars.insert(c);
		}

		return chars;

	};

	inline bool containsDups(unordered_set<char> &chars, string first, string second) {
		
		for (char c : second) {
			if (chars.find(c) != chars.end())
				return true;
		}

		return false;

	};

};