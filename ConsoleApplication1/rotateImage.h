#pragma once
#include <iostream>
#include <vector>

using namespace std;

class rotateImage {
public:
	void rotate(vector<vector<int>>& matrix) {

		int size = matrix.size();

		vector<vector<int>> rotated(size, vector<int>(size, 0));

		for (int col = 0, i = 0; col < size; col++, i++) {

			for (int row = size - 1, j = 0; row >= 0; row--, j++) {
				rotated[i][j] = matrix[row][col];
			}

			print(rotated);

		}

		matrix = rotated;

	};

private:
	void print(vector<vector<int>>& matrix) {

		for (int i = 0; i < matrix.size(); i++) {

			for (int j : matrix[i])
				cout << j << "\t";

			cout << endl;

		}

		int stop;
		cout << "\t\t\t\t\t";
		cin >> stop;

	};
};