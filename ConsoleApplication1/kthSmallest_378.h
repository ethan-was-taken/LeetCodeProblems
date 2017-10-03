#pragma once
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class kthSmallest_378 {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {

		priority_queue<int> sorted;

		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[i].size(); j++)
				sorted.push(matrix[i][j]);
		}

		while (sorted.size() != k)
			sorted.pop();

		return sorted.top();
	};

};