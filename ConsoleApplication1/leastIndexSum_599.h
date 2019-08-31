#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#include "printer.h"
#include "stopper.h"

using namespace std;

typedef unordered_map<string, int> hashTable;
class leastIndexSum_599 {
public:
	static vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
		
		hashTable restaurants;
		for (int i = 0; i < list1.size(); i++)
			restaurants[list1[i]] += i;

		int mini = INT_MAX;
		hashTable dups = setUpDups(restaurants, list2, mini);

		return findCommon(restaurants, dups, mini);

	};

private:
	static hashTable setUpDups(hashTable &stores, vector<string> &list2, int &mini) {
		hashTable dups;
		for (int i = 0; i < list2.size(); i++) {
			if (stores.find(list2[i]) != stores.end()) {
				dups[list2[i]] = i + stores.find(list2[i])->second;
				mini = min(mini, i + stores.find(list2[i])->second);
			}
		}
		return dups;
	};

	static vector<string> findCommon(hashTable &stores, hashTable &dups, int mini) {
		vector<string> toReturn;
		for (auto curr : dups) {
			if (curr.second == mini)
				toReturn.push_back(curr.first);
		}
		return toReturn;
	};
};