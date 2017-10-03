#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class pascalsTriangle {
public:
	vector<vector<int>> generate(int numRows) {
		
		if (numRows <= 2)
			return begEdgeCases(numRows);

		vector<vector<int>> pascal;
		vector<int> row;
		
		row.push_back(1);
		pascal.push_back(row);
		
		row.push_back(1);
		pascal.push_back(row);
		row.clear();

		for (int i = 2; i < numRows; i++) {

			row.push_back(1);

			vector<int> prevRow = pascal.back();
			for (int i = 1; i < prevRow.size(); i++)
				row.push_back(prevRow[i - 1] + prevRow[i]);
			
			row.push_back(1);

			pascal.push_back(row);

			row.clear();

		}

		return pascal;

	};

private:
	inline vector<vector<int>> begEdgeCases(int size) {

		vector<vector<int>> pascal;

		if (size == 0)
			return pascal;

		vector<int> row;

		row.push_back(1);
		pascal.push_back(row);

		if (size == 1)
			return pascal;

		row.push_back(1);
		pascal.push_back(row);
		row.clear();

		if (size == 2)
			return pascal;

	};

};