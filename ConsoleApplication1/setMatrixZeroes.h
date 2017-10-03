#pragma once
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

class setMatrixZeroes {
public:
	void setZeroes(vector<vector<int>>& matrix) {

		/*
		1.	(PASS 1) iterate over matrix
				whenever you encounter a 0, note its row and col in a set
		2.	(PASS 2) iterate over matrix
				Check if matrix[row][col]'s row or col is "tagged" -> if one of 
				 them is: set it matrix[row][col] to 0
		*/

		unordered_set<int> rowsTagged;
		unordered_set<int> colsTagged;
		for (int row = 0; row < matrix.size(); row++) {

			for (int col = 0; col < matrix[row].size(); col++) {

				if (matrix[row][col] == 0) {
					rowsTagged.insert(row);
					colsTagged.insert(col);
				}

			}

		}

		printSet(rowsTagged, colsTagged);
		printMatrix(matrix);

		stopper();

		for (int row = 0; row < matrix.size(); row++) {

			for (int col = 0; col < matrix[row].size(); col++) {

				bool hasRow = rowsTagged.find(row) != rowsTagged.end();
				bool hasCol = colsTagged.find(col) != colsTagged.end();

				if (hasRow || hasCol)
					matrix[row][col] = 0;

			}

		}

		printMatrix(matrix);

	};

private:
	void stopper() {
		int stop;
		cout << "\t\t\t\t\t";
		cin >> stop;
	};

	void printSet(unordered_set<int> rows, unordered_set<int> cols) {

		unordered_set<int>::iterator rowIt = rows.begin();
		unordered_set<int>::iterator colIt = cols.begin();

		for (; rowIt != rows.end(); rowIt++) {

			cout << *(rowIt) << "\t";

		}

		cout << endl;

		for (; colIt != cols.end(); colIt++) {

			cout << *(colIt) << "\t";

		}
		cout << endl;
		cout << endl;

	};

	void printMatrix(vector<vector<int>>& matrix) {

		for (int row = 0; row < matrix.size(); row++) {

			for (int col = 0; col < matrix[row].size(); col++) {
				cout << matrix[row][col] << "\t";
			}

			cout << endl;

		}
		cout << endl;
		cout << endl;

	};

};