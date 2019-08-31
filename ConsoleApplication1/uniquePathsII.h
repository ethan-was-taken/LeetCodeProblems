#pragma once
#include <iostream>
#include <vector>

#include "printer.h"

using namespace std;

class uniquePathsII {
public:
	static int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

		vector<vector<int>> memo;
		setupMemo(obstacleGrid, memo);

		for (int row = 1; row < memo.size(); row++) {
			for (int col = 1; col < memo[row].size(); col++) {
				if (obstacleGrid[row][col] != 1)
					memo[row][col] = memo[row - 1][col] + memo[row][col - 1];
			}
		}

		return memo.back().back();

	};

private:
	static void setupMemo(vector<vector<int>> &grid, vector<vector<int>> &memo) {

		for (int i = 0; i < grid.size(); i++)
			memo.push_back(vector<int>(grid[0].size(), 0));

		for (int row = 0; row < grid.size(); row++) {

			for (int col = 0; col < grid[row].size(); col++) {

				if (row == 0 && grid[row][col] != 1) 
					memo[row][col] = 1;
				else if (col == 0 && grid[row][col] != 1)
					memo[row][col] = 1;
				
				if (row > 0 && memo[row - 1][col] == 0)
					memo[row][col] = 0;
				if (col >= 1 && memo[row][col - 1] == 0)
					memo[row][col] = 0;
				
			}

		}

	};
	
};