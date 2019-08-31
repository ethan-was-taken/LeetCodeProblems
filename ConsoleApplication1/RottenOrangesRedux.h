#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <memory>

#include <stdlib.h> 
#include "printer.h"

#define FRESH 1
#define ROTTEN 2

using namespace std;

class RottenOrangesRedux {
public:
	int orangesRotting(vector<vector<int>> &grid) {

		setup(grid);
		addRottenCoordinatesToQueue();
		addEndOfPassIndicator();
		breadthFirst();

		doubleCheckResult();

		return result;

	};

private:
	vector<vector<int>> grid;	
	queue<pair<int, int>> que;
	int result;

	void setup(vector<vector<int>> &_grid) {
		grid = _grid;
		result = 0;
	};

	void addRottenCoordinatesToQueue() {
		
		for (int row = 0; row < grid.size(); row++) {
			for (int col = 0; col < grid[0].size(); col++) {
				if (grid[row][col] == ROTTEN)
					que.push(make_pair(row, col));
			}
		}

	};

	void addEndOfPassIndicator() {
		if (!que.empty())
			que.push(make_pair<int, int>(-1, -1));
	};

	void breadthFirst() {

		while (!que.empty()) {

			pair<int, int> curr = que.front();
			que.pop();

			if (isEndOfPass(curr)) {
				result = !que.empty() ? result + 1 : result;
				addEndOfPassIndicator();						
				continue;
			}				

			checkAdjacentCells(curr);

		}

	};

	inline bool isEndOfPass(pair<int, int> &curr) {
		return curr.first == -1 && curr.second == -1;
	};

	void checkAdjacentCells(pair<int, int> &curr) {

		// Left
		if (isCellOfType(curr.first, curr.second + 1, FRESH))
			addAdjacentCellsToQueue(curr, 0, 1);

		// down
		if (isCellOfType(curr.first + 1, curr.second, FRESH))
			addAdjacentCellsToQueue(curr, 1, 0);

		// right
		if (isCellOfType(curr.first, curr.second - 1, FRESH))
			addAdjacentCellsToQueue(curr, 0, -1);

		// up
		if (isCellOfType(curr.first - 1, curr.second, FRESH))
			addAdjacentCellsToQueue(curr, -1, 0);

	}

	inline bool isCellOfType(int row, int col, int type) {

		bool isValidRowPos = row >= 0 && row < grid.size();
		bool isValidColPos = col >= 0 && col < grid[0].size();

		return isValidRowPos && isValidColPos && grid[row][col] == type;

	};

	inline void addAdjacentCellsToQueue(pair<int, int> &curr, int rowModifier, int colModifier) {
		grid[curr.first + rowModifier][curr.second + colModifier] = ROTTEN;
		que.push(make_pair(curr.first + rowModifier, curr.second + colModifier));		
	};

	void doubleCheckResult() {
		
		for (int row = 0; row < grid.size(); row++) {
			for (int col = 0; col < grid[0].size(); col++) {
				if (grid[row][col] == FRESH)
					result = -1;
			}
		}

	};

};