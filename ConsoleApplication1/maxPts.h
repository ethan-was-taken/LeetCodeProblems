#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

#define NULL_PT Point(-5, -5)

//Solution
//https://leetcode.com/submissions/detail/104083071/

// Another way of doing this would be to have two hashmaps, one where the key is the col. index
//   and another where the key is the row
// Go through the original vector, and look for points that are next to it (bottom or right) and just go from point to point counting

class maxPts {
	public:
		int maxPoints(vector<Point>& points) {

			cout << points.size() << endl;

			// Add these here:
			if (points.size() == 0)
				return 0;
			if (points.size() == 1)
				return 1;

			const pair<int, int> dimensions = findDimensions(points);
			// Setup the grid size so thats its basically an array
			grid.resize(dimensions.first);
			for (int i = 0; i < dimensions.first; i++)
				grid[i].resize(dimensions.second);

			fillGrid(points);
			//printGrid();
			removeSinglePts();
			//printGrid();

			int longestLine = 0;

			int temp = countRows();
			longestLine = (temp > longestLine) ? temp : longestLine;
			
			temp = countCols();
			longestLine = (temp > longestLine) ? temp : longestLine;

			grid.clear();
			grid.~vector();

			longestLine = (longestLine == 0) ? 1 : longestLine;
			
			return longestLine;

		};

	private:
		void printGrid() {
			cout << "-----PRINT-----" << endl << endl;
			for (unsigned int row = 0; row < grid.size(); row++) {
				for (unsigned int col = 0; col < grid[row].size(); col++) {

					if (!hasOrigin && grid[row][col].x == 0 && grid[row][col].y == 0)
						cout << ".\t";
					else if (grid[row][col].x == row && grid[row][col].y == col)
						cout << "X\t";
					else
						cout << ".\t";

				}
				cout << endl;
			}

		};

		// int1 = row size; int2 = col size
		pair<int, int> findDimensions(vector<Point>& points) {
			//cout << "-----FIND_DIM-----" << endl << endl;
			int rowSize = 0;
			int colSize = 0;

			for (unsigned int i = 0; i < points.size(); i++) {
				if (points[i].x > rowSize)
					rowSize = points[i].x;
				if (points[i].y > colSize)
					colSize = points[i].y;
			}

			rowLength = rowSize;
			colLength = colSize;

			return pair<int, int>(++rowSize, ++colSize);
		};

		void fillGrid(vector<Point>& points) {
			//cout << "-----FILL_GRD-----" << endl << endl;
			for (unsigned int i = 0; i < points.size(); i++) {
				int row = points[i].x;
				int col = points[i].y;

				if (row == 0 && col == 0)
					hasOrigin = true;

				grid[row][col] = points[i];
			}
		};

		// Note: while this uses a nested for loop, its still O(n),
		//  since you only visit each Point once
		void removeSinglePts() {
			//cout << "-----RM_SNGL------" << endl << endl;

			for (unsigned int row = 0; row < grid.size(); row++) {
				for (unsigned int col = 0; col < grid[row].size(); col++) {
					if (isPointSingle(row, col))
						grid[row][col] = NULL_PT;
				}
			}

		};

		bool isPointSingle(int row, int col) {

			bool hasLeft = false;
			bool hasRight = false;
			bool hasTop = false;
			bool hasBot = false;

			if (!hasOrigin && grid[row][col].x == 0 && grid[row][col].y == 0)
				return true;
			else if (grid[row][col].x == row && grid[row][col].y == col) {
				//do nothing
			}				
			else
				return true;

			//cout << "-----IS_SNGL------" << endl << endl;

			// Look left
			if (col > 0) {
				// if left col doesnt have the same row || left col.y != curr col.y - 1
				hasLeft = (grid[row][col - 1].x != grid[row][col].x ||
					grid[row][col - 1].y != (grid[row][col].y - 1)) ? false : true;
			}
			// Look right
			if (col < rowLength - 1) {
				// if right col doesnt have the same row || right col.y != curr col.y + 1
				hasRight = (grid[row][col + 1].x != grid[row][col].x ||
					grid[row][col + 1].y != (grid[row][col].y + 1)) ? false : true;
			}
			// Look above
			if (row > 0) {
				hasTop = (grid[row - 1][col].x != grid[row][col].x - 1 ||
					grid[row - 1][col].y != (grid[row][col].y)) ? false : true;
			}
			// Look below
			if (row < rowLength - 1) {
				hasBot = (grid[row + 1][col].x != grid[row][col].x + 1 ||
					grid[row + 1][col].y != (grid[row][col].y)) ? false : true;
			}
			
			return !hasLeft && !hasRight && !hasTop && !hasBot;
		}

		int countRows() {
			//cout << "-----COUNT_ROWS-----" << endl << endl;

			int longest = 0;

			for (unsigned int row = 0; row < grid.size(); row++) {

				int tempLongest = 0;

				for (unsigned int col = 0; col < grid[row].size(); col++) {

					Point curr = grid[row][col];

					//cout << "Looking at: " << curr.x << " " << curr.y << endl;
					
					// If nothing at this location, reset longest && move on
					if (curr.x == NULL_PT.x && curr.y == NULL_PT.y) {
						tempLongest = 0;
						continue;
					}

					tempLongest++;

				}

				longest = (longest < tempLongest) ? tempLongest : longest;
			}

			return longest;
		};

		int countCols() {
			//cout << "-----COUNT_COLS-----" << endl << endl;

			int longest = 0;

			for (unsigned int col = 0; col < colLength; col++) {

				int tempLongest = 0;

				for (unsigned int row = 0; row < rowLength; row++) {

					Point curr = grid[row][col];

					//cout << "Looking at: " << curr.x << " " << curr.y << endl;

					// If nothing at this location, reset longest && move on
					if (curr.x == NULL_PT.x && curr.y == NULL_PT.y) {
						tempLongest = 0;
						continue;
					}

					tempLongest++;

				}

				longest = (longest < tempLongest) ? tempLongest : longest;
			}

			return longest;
		};

		//----------Global Variables----------
		vector<vector<Point>> grid;
		int rowLength;
		int colLength;
		bool hasOrigin = false;

};