#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class numberIslands {
public:
	int numIslands(vector<vector<char>>& grid) {

		int count = 0;
		for (int row = 0; row < grid.size(); row++) {

			for (int col = 0; col < grid[row].size(); col++) {

				if (grid[row][col] == '1') {
					count++;
					sinkLand(grid, row, col);
				}

			}

		}

		return count;

	};

private:
	void sinkLand(vector<vector<char>>& grid, int row, int col) {

		grid[row][col] = '0';

		// Go right
		if (col + 1 < grid[row].size() && grid[row][col + 1] == '1')
			sinkLand(grid, row, col + 1);

		// Go down
		if (row + 1 < grid.size() && grid[row + 1][col] == '1')
			sinkLand(grid, row + 1, col);

		// Go left
		if (col - 1 >= 0 && grid[row][col - 1] == '1')
			sinkLand(grid, row, col - 1);

		// Go up
		if (row - 1 >= 0 && grid[row - 1][col] == '1')
			sinkLand(grid, row - 1, col);

	};

};