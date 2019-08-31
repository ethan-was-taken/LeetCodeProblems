#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class DeleteColumns {
public:
	int minDeletionSize(vector<string>& strings) {



	};

	// O(nm) where n = strings.size() & m = strings[i].size()
	int minDeletionSizeNaieve(vector<string> &strings) {

		int numDeletions = 0;

		for (int col = 0; col < strings[0].size(); col++) {

			for (int row = 0; row < strings.size(); row++) {

				if (isLessThanNeighborCol(strings, col, row))
					continue;

				numDeletions++;
				break;

			}

		}

		return numDeletions;

	};

private:
	inline bool isLessThanNeighborCol(const vector<string> &strings, const int &col, const int &row) const {
		
		bool isColValid = col < strings[0].size();
		bool isNextRowValid = row + 1 < strings.size();

		return !isNextRowValid ? true : isColValid && strings[row][col] <= strings[row + 1][col];

	};


};