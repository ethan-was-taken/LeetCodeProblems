#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class pascalsTriangleII {
public:
	vector<int> getRow(int rowIndex) {

		vector<int> prevRow(1,1);
		vector<int> currRow;

		for (int i = 0; i < rowIndex; i++) {

			currRow.push_back(1);

			for (int i = 1; i < prevRow.size(); i++) {
				currRow.push_back(prevRow[i - 1] + prevRow[i]);
				//print(currRow);
			}

			currRow.push_back(1);
			prevRow = currRow;

			currRow.clear();

			//print(prevRow);


		}

		return prevRow;


	};

private:
	void print(vector<int> ans) {

		for (auto i : ans) {
			cout << i << "\t";
		}
		cout << endl;

		int stop;
		cout << "\t\t\t\t\t";
		cin >> stop;
	};

};