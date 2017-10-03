#pragma once
#include <iostream>
#include <vector>

using namespace std;

class reshapeMatrix {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {

		int numRows = nums.size();
		int numCols = nums[0].size();
		if (r * c != numRows * numCols || nums.empty())
			return nums;

		vector<vector<int>> newMatrix = initialize(r, c);

		print(newMatrix);
		
		int i2 = 0;
		int j2 = 0;

		for (int i = 0; i < numRows; i++) {

			for (int j = 0; j < numCols; j++) {

				newMatrix[i2][j2] = nums[i][j];

				print(newMatrix);

				increment(i2, j2, r, c, false);
				if (j2 == 0)
					increment(i2, j2, r, c, true);

			}
						
		}

		return newMatrix;

	};

private:
	inline vector<vector<int>> initialize(int row, int col) {

		vector<vector<int>> toReturn;

		for (int i = 0; i < row; i++) {
			
			vector<int> temp;
			
			for (int j = 0; j < col; j++)
				temp.push_back(0);
			
			toReturn.push_back(temp);

		}

		return toReturn;

	};

	// returns i as -1 if we've reached the end of the matrix
	// returns j as 0 once it needs to be wrapped around
	inline void increment(int &i, int &j, int row, int col, bool incRow) {

		if (incRow && i + 1 < row) {
			cout << "inc i to:\t" << i + 1 << endl;
			i++;
			return;
		}
		else if (incRow) {
			cout << "inc i to:\t" << -1 << endl;
			i = -1;
			return;
		}

		if (j + 1 < col) {
			cout << "inc j to:\t" << j + 1 << endl;
			j++;
		}
		else {
			cout << "inc j to:\t" << 0 << endl;
			j = 0;
		}

	};

	inline void print(vector<vector<int>> mat) {

		for (int i = 0; i < mat.size(); i++) {

			for (int j : mat[i]) {
				cout << j << "\t";
			}
			cout << endl;

		}
		
		int stop;
		cout << "\t\t\t\t\t";
		cin >> stop;

	}

};