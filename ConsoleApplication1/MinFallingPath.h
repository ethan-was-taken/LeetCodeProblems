#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>

#include "printer.h"

using namespace std;

class MinFallingPath {
public:
	int minFallingPathSum(vector<vector<int>> &nums) {

		this->nums = &nums;

		for (int row = nums.size() - 2; row >= 0; row--) {
			for (int col= nums[row].size() - 1; col >= 0; col--)
				setMinPathValueAt(row, col);
		}

		int res = INT_MAX;
		for (int curr : (*this->nums)[0])
			res = min(res, curr);

		return res;

	};

private:
	vector<vector<int>> *nums;

	inline void setMinPathValueAt(int row, int col) {

		int mini = INT_MAX;

		if (isInBounds(row + 1, col))
			mini = min(mini, (*nums)[row + 1][col]);

		if (isInBounds(row + 1, col + 1))
			mini = std::min(mini, (*nums)[row + 1][col + 1]);

		if (isInBounds(row + 1, col - 1))
			mini = std::min(mini, (*nums)[row + 1][col - 1]);

		(*nums)[row][col] += mini;

	};

	inline bool isInBounds(int row, int col) {

		if (row < 0 || col < 0)
			return false;
		else if (row >= nums->size() || col >= nums[0].size())
			return false;
		else 
			return true;

	};

};