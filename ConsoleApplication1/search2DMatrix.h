#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class search2DMatrix {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {

		if (matrix.size() == 0 || matrix[0].empty())
			return false;

		pair<int, int> bounds = findBoundaries(matrix, target);

		for (int i = bounds.first; i <= bounds.second; i++) {

			if (binarySearch(matrix[i], target, 0, matrix[i].size() - 1))
				return true;

			if (i + 1 >= matrix.size())
				break;
		}

		return false;
	};

private:
	inline bool binarySearch(vector<int> &row, int target, int lptr, int rptr) {

		int mptr = (rptr - lptr) / 2 + lptr;

		if (rptr < lptr)
			return false;

		if (row[mptr] == target)
			return true;
		else if (row[mptr] > target)
			return binarySearch(row, target, lptr, mptr - 1);
		else
			return binarySearch(row, target, mptr + 1, rptr);

	};

	pair<int, int> findBoundaries(vector<vector<int>>& matrix, int target) {

		int beg = INT_MIN;
		int end = INT_MAX;

		for (int i = 0; i < matrix.size(); i++) {

			if (beg == INT_MIN && matrix[i][matrix[i].size() - 1] > target)
				beg = (i != 0) ? i - 1 : 0;
			if (end == INT_MAX && matrix[i][0] > target)
				end = i;
			if (beg != INT_MIN && end != INT_MAX)
				break;

		}

		beg = (beg == INT_MIN) ? 0 : beg;

		if (end == INT_MAX)
			end = matrix.size() - 1;
		if (end == 0)
			end = 1;

		return make_pair(beg, end);
	};
};