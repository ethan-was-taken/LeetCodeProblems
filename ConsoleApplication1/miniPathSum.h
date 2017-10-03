#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class miniPathSum {
public:
	int minPathSum(vector<vector<int>>& grid) {

		// edge cases here 
		if (grid.empty())
			return 0;

		initialize(grid);
		print();

		for (int row = 1; row < grid.size(); row++) {

			for (int col = 1; col < grid[row].size(); col++) {
			
				memo[row][col] = min(memo[row - 1][col], memo[row][col - 1]) + grid[row][col];
				print();

			}

		}

		return memo[grid.size() - 1][grid[0].size() - 1];

	};

private:
	void print() {
		cout << "---------------------------------" << endl;
		for (int row = 0; row < memo.size(); row++) {

			for (int col = 0; col < memo[row].size(); col++) {

				cout << memo[row][col] << "\t";

			}

			cout << endl;

		}

		stopper();
		cout << "---------------------------------" << endl << endl;
	};

	void stopper() {
		int stop;
		cout << "\t\t\t\t\t";
		cin >> stop;
	};

	void initialize(vector<vector<int>> grid) {

		for (int row = 0; row < grid.size(); row++) {

			vector<int> temp;

			for (int col = 0; col < grid[row].size(); col++) {

				if (row == 0 && col == 0) {
					temp.push_back(grid[row][col]);
				}
				else if (row == 0 && col > 0) {
					temp.push_back(grid[row][col] + temp.back());
				}
				else if (row > 0 && col == 0) {
					temp.push_back(grid[row][col] + memo[row - 1][col]);
				}
				else 
					temp.push_back(0);

			}

			memo.push_back(temp);

		}

	};

	vector<vector<int>> memo;

};