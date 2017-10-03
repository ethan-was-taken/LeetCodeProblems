#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class longestIncPath {
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {

		if (matrix.empty())
			return 0;

		longestPath = INT_MIN;
		fillMemo(matrix);

		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[i].size(); j++) {
				if (memo[i][j] == -1)
					dfs(matrix, i, j);
			}
		}

		return longestPath;
	};

private:
	inline int dfs(vector<vector<int>>& matrix, int row, int col) {

		// Base case; Dont have to worry about NULL because of isValid(...)
		if (memo[row][col] != -1)
			return memo[row][col];

		int longest = INT_MIN;//try making this 1 and removing line 46 & 47

		// If possible, go Left
		if (isValid(matrix, row, col + 1, row, col))
			longest = max(longest, dfs(matrix, row, col + 1) + 1);

		// If possible, go Down
		if (isValid(matrix, row + 1, col, row, col))
			longest = max(longest, dfs(matrix, row + 1, col) + 1);

		// If possible, go Right
		if (isValid(matrix, row, col - 1, row, col))
			longest = max(longest, dfs(matrix, row, col - 1) + 1);

		// If possible, go Up
		if (isValid(matrix, row - 1, col, row, col))
			longest = max(longest, dfs(matrix, row - 1, col) + 1);

		if (longest == INT_MIN)
			longest = 1;

		memo[row][col] = longest;
		longestPath = (longest > longestPath) ? longest : longestPath;

		return longest;
	};

	inline bool isValid(vector<vector<int>>& matrix, int row, int col, int prevRow, int prevCol) {

		int rowUpper = matrix.size() - 1;
		int colUpper = matrix[0].size() - 1;

		// Theres a better, cleaner, way to do this. But i cant think of any rn
		if (row >= 0 && col >= 0 && prevRow >= 0 &&
			prevCol >= 0 && row <= rowUpper && col <= colUpper &&
			prevRow <= rowUpper	&& prevCol <= colUpper &&
			matrix[row][col] > matrix[prevRow][prevCol]
			) {
			return true;
		}

		return false;
	};

	inline void fillMemo(vector<vector<int>>& matrix) {
		for (int i = 0; i < matrix.size(); i++)
			memo.push_back(vector<int>(matrix[i].size(), -1));
	}

	//-----Global Vars-----
	vector<vector<int>> memo;
	int longestPath;

};