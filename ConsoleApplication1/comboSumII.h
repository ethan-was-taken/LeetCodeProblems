#pragma once
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

class comboSumII {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

		if (candidates.empty())
			return sums;
		
		sorted = candidates;
		sort(sorted.begin(), sorted.end());

		depthFirst(target, 0, 0, vector<int>(), 0);
		
		return sums;
	};
private:
	inline bool depthFirst(int target, int currIndex, int currSum, vector<int> path, int hashedPath) {
		
		//print(target, currIndex, currSum, path);

		// ~base cases~
		if (currSum > target)
			return true;
		else if (currSum == target) {
			
			//int hashedVector = hash(path);
			if (hashes.find(hashedPath) == hashes.end()) {
				hashes.insert(hashedPath);
				sums.push_back(path);
			}

			return true;

		}

		for (int i = currIndex; i < sorted.size(); i++) {

			/*
			Another possible way to do this would be to check if currindex == 0 (i.e. see if we're at the
			"root") and skip the duplicates. That way you wouldn't have to hash the path vectors
			*/

			path.push_back(sorted[i]);
			bool result = depthFirst(target, i + 1, currSum + sorted[i], path, hash(sorted[i], hashedPath));
			path.pop_back();

			if (result)
				break;

		}

		return false;
	};

	void print(int target, int currIndex, int currSum, vector<int> path) {
		cout << "target: " << target << endl;
		cout << "currIndex: " << currIndex << endl;
		cout << "currSum: " << currSum << endl;
		cout << "path: ";
		for (int i : path) {
			cout << i << " -> ";
		}
		cout << endl << endl;

	};

	//https://stackoverflow.com/questions/37007307/fast-hash-function-for-stdvector
	int hash(vector<int> path) {

		int hash = 0;

		for (int i = 0; i < path.size(); i++)
			hash += std::hash<int>()(path[i]) + 0x9e3779b9 + (hash << 6) + (hash >> 2);

		return hash;

	}

	//https://stackoverflow.com/questions/37007307/fast-hash-function-for-stdvector
	int hash(int curr, int hash) {
		
		hash += std::hash<int>()(curr) + 0x9e3779b9 + (hash << 6) + (hash >> 2);

		return hash;

	}

	//---Global Vars---
	vector<int> sorted;
	unordered_set<int> hashes;
	vector<vector<int>> sums;
};