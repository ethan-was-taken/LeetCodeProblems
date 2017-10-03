#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class islandPerim {
public:
	int islandPerimeter(vector<vector<int>>& grid) {

		int perim = 0;

		for (int row = 0; row < grid.size(); row++) {

			for (int col = 0; col < grid[row].size(); col++) {
			
				if (grid[row][col] != 1)
					continue;

				// Check above
				if (row - 1 < 0 || grid[row - 1][col] == 0)
					perim++;

				// Check left
				if (col + 1 >= grid[row].size() || grid[row][col + 1] == 0)
					perim++;

				// Check down
				if (row + 1 >= grid.size() || grid[row  + 1][col] == 0)
					perim++;
				
				// Check right
				if (col - 1 < 0 || grid[row][col - 1] == 0)
					perim++;

			}

		}

		return perim;

	};

private:

};