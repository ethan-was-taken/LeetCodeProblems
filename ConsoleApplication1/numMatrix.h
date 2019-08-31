#pragma once
#include <iostream>
#include <vector>

#include "stopper.h"

using namespace std;

class NumMatrix {
public:
	NumMatrix(vector<vector<int>> matrix) {

		if (matrix.empty() || matrix[0].empty()) 
			return;
		
		for (int row = 0; row < matrix.size(); row++) {
			dp.push_back(vector<int>(matrix[row].size() + 1, 0));
			for (int col = 0; col < matrix[0].size(); col++)
				dp[row][col + 1] = dp[row][col] + matrix[row][col];
		}

		print(dp);

	};

	int sumRegion(int row1, int col1, int row2, int col2) {

		//if (row2 >= matrix.size())
		//	return -1;
		//else if (col2 >= matrix[0].size())
		//	return -1;

		int sum = 0;
		for (int row = row1; row <= row2; row++) {
			sum += dp[row][col2 + 1];
			sum -= dp[row][col1];

			cout << "row:\t" << row << endl;
			cout << "col2:\t" << col2 << endl;
			cout << "col1:\t" << col1 << endl;
			cout << "dp[row][col2 + 1]:\t" << dp[row][col2 + 1] << endl;
			cout << "dp[row][col1]:\t" << dp[row][col1] << endl;
			stopper::stop();

		}

		return sum;

	};

private:
	void print(vector<vector<int>> &arr) {
		for (int row = 0; row < arr.size(); row++) {
			for (int col = 0; col < arr[0].size(); col++)
				cout << arr[row][col] << "\t";
			cout << endl;
		}
	};

	vector<vector<int>> matrix;
	vector<vector<int>> dp;
};

/**
* Your NumMatrix object will be instantiated and called as such:
* NumMatrix obj = new NumMatrix(matrix);
* int param_1 = obj.sumRegion(row1,col1,row2,col2);
*/