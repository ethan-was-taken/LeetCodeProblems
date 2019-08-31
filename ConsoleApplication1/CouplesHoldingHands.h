#pragma once
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class CouplesHoldingHands {
public:
	int minSwapsCouples(vector<int> &row) {
		
		setup(row);
		int result = 0;

		for (int i = 0; i < row.size(); i += 2) {

			if (isCouple(i))
				continue;

			int significantOther = getMissingSignificantOther(i);
			int significantOtherIndex = indices.find(significantOther)->second;

			swapSeats(i + 1, significantOtherIndex);

			result++;

		}

		return result;

	};

private:
	unordered_map<int, int> indices;
	vector<int> row;

	void setup(vector<int> &row) {
		this->row = row;
		for (int i = 0; i < row.size(); i++)
			indices[row[i]] = i;
	};

	bool isCouple(int startIndex) {
		bool isEven = row[startIndex] % 2 == 0;
		if (isEven)
			return row[startIndex + 1] == row[startIndex] + 1;
		return row[startIndex + 1] == row[startIndex] - 1;
	};

	int getMissingSignificantOther(int input) {
		bool isEven = row[input] % 2 == 0;
		return isEven ? row[input] + 1 : row[input] - 1;
	};

	void swapSeats(int neighborIndex, int significantOtherIndex) {
		
		indices[row[neighborIndex]] = significantOtherIndex;
		indices[row[significantOtherIndex]] = neighborIndex;

		int temp = row[neighborIndex];
		row[neighborIndex] = row[significantOtherIndex];
		row[significantOtherIndex] = temp;

	};

};