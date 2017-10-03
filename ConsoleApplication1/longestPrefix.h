#pragma once
#include <iostream>
#include <string>
#include <vector>
   

using namespace std; 
class longestPrefix {
public:
	string longestCommonPrefix(vector<string>& strs) {

		if (strs.size() == 0)
			return "";
		else if (strs.size() == 1)
			return strs[0];
		else if (strs.size() == 2)
			return findCommonPrefix(strs[0], strs[1]);

		string longPrefix = findShortestStr(strs);
		for (string curr : strs) {
			if (curr == "")
				return "";
			longPrefix = findCommonPrefix(curr, longPrefix);
		}

		return longPrefix;
	};

private:
	inline string findShortestStr(vector<string>& strs) {

		string shortest = /*(strs.size() == 2) ? "" : */strs[0];

		for (string str : strs) {
			if (str.size() < shortest.size())
				shortest = str;
		}

		return shortest;
	};

	inline string findCommonPrefix(string curr, string currPrefix) {

		int i = 0;
		for (; i < currPrefix.size(); i++) {
			if (curr[i] != currPrefix[i])
				break;
		}

		return currPrefix.substr(0, i);
	}

};