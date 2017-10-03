#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class maxSquare {
public:
	int maximalSquare(vector<vector<char>>& matrix) {

		// ~Precursory edge cases here~
		if (matrix.empty())
			return 0;

		/*
		1) fill in memo's first row and column -> this will be the exact same as the matrix's

		2) find the min of: [row][col - 1], [row - 1][col], and [row - 1][column - 1] and add one to
		that (if [row][col] == 0, then memo[row][col] = 0)

		3) keep track of the largest value you have -> return (largest val)^2
		*/

		int largestSquare = fillMemo(matrix);

		for (int row = 1; row < matrix.size(); row++) {

			for (int col = 1; col < matrix[row].size(); col++) {

				if (matrix[row][col] - 48 == 0) {
					memo[row][col] = 0;
					continue;
				}

				int up = memo[row - 1][col];
				int left = memo[row][col - 1];
				int upLeft = memo[row - 1][col - 1];

				int mini = minimum(up, left, upLeft) + 1;

				largestSquare = (largestSquare < mini) ? mini : largestSquare;

				memo[row][col] = mini;

			}

		}

		return (int)pow(largestSquare, 2);

	};

private:
	int fillMemo(vector<vector<char>>& matrix) {

		int maxRow = matrix.size();
		int maxCol = matrix[0].size();

		int toReturn = 0;

		for (int row = 0; row < maxRow; row++) {

			vector<int> curr;

			for (int col = 0; col < maxCol; col++) {

				if (matrix[row][col] - 48 == 1)
					toReturn = 1;

				if (row == 0 || col == 0)
					curr.push_back(matrix[row][col] - 48);
				else
					curr.push_back(-1);

			}

			memo.push_back(curr);

		}

		return toReturn;

	};

	// Just to make the code a little easier to read
	inline int minimum(int first, int second, int third) {
		return min(min(first, second), third);
	};

	//-----Global Vars-----
	vector<vector<int>> memo;
};