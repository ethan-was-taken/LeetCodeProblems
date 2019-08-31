#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class groupAnagram {
public:
	static vector<vector<string>> groupAnagrams(vector<string>& strs) {

		unordered_map<string, vector<string>> anagramHolder;
		for (string curr : strs) {
			string toAdd = curr;
			sort(curr.begin(), curr.end());
			anagramHolder[curr].push_back(toAdd);
		}
			

		vector<vector<string>> result;
		for (auto curr : anagramHolder)
			result.push_back(curr.second);
						
		return result;

	};

};