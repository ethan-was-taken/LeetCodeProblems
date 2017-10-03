#pragma once
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class isomorphicStrings {
public:
	bool isIsomorphic(string s, string t) {

		if (s.size() != t.size())
			return false;

		unordered_map<char, char> mappingForward;
		unordered_map<char, char> mappingBackward;
		
		for (int i = 0; i < s.size(); i++) {

			if (mappingForward.find(s[i]) != mappingForward.end() && mappingForward[s[i]] != t[i])
				return false;
			if (mappingBackward.find(t[i]) != mappingBackward.end() && mappingBackward[t[i]] != s[i])
				return false;

			mappingForward[s[i]] = t[i];
			mappingBackward[t[i]] = s[i];

		}

		return true;

	};


private:



};