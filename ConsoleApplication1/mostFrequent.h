#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>


using namespace std;

class mostFrequent {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		
		unordered_map<int, int> frequency;
		for (int i : nums)
			frequency[i]++;
		
		priority_queue<pair<int, int>> sorted;
		for (auto it = frequency.begin(); it != frequency.end(); it++)
			sorted.push( pair<int, int>(it->second, it->first) );

		vector<int> mostFrequent;
		for (int i = 0; i < k && sorted.size() > 0; i++) {
			mostFrequent.push_back(sorted.top().second);
			sorted.pop();
		}

		return mostFrequent;
	};

};