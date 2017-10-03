#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class validAnagram {
public:
	bool isAnagram(string s, string t) {

		unordered_map<int, int> sChars;
		unordered_map<int, int> tChars;

		addToMap(sChars, s);
		addToMap(tChars, t);

		if (sChars.size() != tChars.size())
			return false;

		unordered_map<int, int>::iterator it = sChars.begin();
		for (; it != sChars.end(); it++) {

			pair<int, int> curr = *it;

			if (tChars.find(curr.first) == tChars.end())
				return false;
			else if (tChars.find(curr.first)->second != curr.second)
				return false;

		}

		return true;

	};

private:
	void addToMap(unordered_map<int, int> &chars, string str) {

		for (int i = 0; i < str.size(); i++) {

			if (chars.find(str[i]) != chars.end()) {
				chars.find(str[i])->second++;
			}
			else
				chars.insert(pair<int, int>(str[i], 1));

		}

	};

}; 