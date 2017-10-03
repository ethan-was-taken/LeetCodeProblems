#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class spiralMatrix {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {

		if (matrix.empty())
			return vector<int>();

		vector<vector<bool>> path(
			matrix.size(),
			vector<bool>(matrix[0].size(), false)
		);

		vector<int> spiral;
		int i = 0;
		int j = -1;

		while (true) {

			bool wentLeft	= false;
			bool wentDown	= false;
			bool wentRight	= false;
			bool wentUp		= false;

			// Go left while possible
			j++;
			for (; j < matrix[i].size() && path[i][j] != true; j++) {
				//cout << "left" << endl;
				//print(path, spiral, i, j);
				set(path, spiral, wentLeft, i, j, matrix[i][j]);
				//cout << 1 << endl;
			}
			j--;

			print(path, spiral, i, j);

			// Go down while possible
			i++;
			for (; i < matrix.size() && path[i][j] != true; i++) {
				cout << "down" << endl;
				set(path, spiral, wentDown, i, j, matrix[i][j]);
			}
			i--;

			print(path, spiral, i, j);

			// Go right while possible
			j--;
			for (; j >= 0 && path[i][j] != true; j--) {
				cout << "right" << endl;
				set(path, spiral, wentRight, i, j, matrix[i][j]);
			}
			j++;

			print(path, spiral, i, j);

			// Go up while possible
			i--;
			for (; i >= 0 && path[i][j] != true; i--) {
				cout << "up" << endl;
				set(path, spiral, wentUp, i, j, matrix[i][j]);
			}
			i++;

			print(path, spiral, i, j);

			// If we couldn't go anywhere then we're done
			if (!wentLeft && !wentDown && !wentRight && !wentUp)
				break;

			cout << "------------------------------------" << endl << endl;

		}

		return spiral;

	};

private:
	inline void set(vector<vector<bool>>& path, vector<int> &spiral, bool &went, int i, int j, int curr) {

		went = true;

		path[i][j] = true;
		spiral.push_back(curr);

	};

	void print(vector<vector<bool>> path, vector<int> spiral, int i, int j) {
	
		cout << "i:\t" << i << endl;
		cout << "j:\t" << j << endl;

		for (int i = 0; i < path.size(); i++) {
			for (int curr : path[i]) {
				cout << curr << "\t";
			}
			cout << endl;
		}
		
		cout << endl;

		for (int i : spiral) {
			cout << i << "\t";
		}
		cout << endl;

		int stop;
		cout << "\t\t\t\t\t";
		cin >> stop;

	};

};