#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class canPlaceFlowers_605 {
public:
	bool canPlaceFlowers(vector<int> &flowerbed, int n) {

		int count = 0;
		for (int i = 0; i < flowerbed.size() && count < n; i++) {
			if (isValid(flowerbed, i))
				update(flowerbed, i, count);
		}

		return count == n;

	};

private:
	inline bool isValid(vector<int> &flowerbed, int i) {
		return	isValidInBetween(flowerbed, i) ||
				isValidBeginning(flowerbed, i) ||
				isValidInEnding(flowerbed, i);
	};

	inline bool isValidInBetween(vector<int> &flowerbed, int i) {
		return  flowerbed[i] == 0 &&
				i - 1 > 0 && flowerbed[i - 1] == 0 &&
				i + 1 < flowerbed.size() && flowerbed[i + 1] == 0;
	};

	inline bool isValidBeginning(vector<int> &flowerbed, int i) {
		return	i == 0 && flowerbed[i] == 0 &&
				i + 1 < flowerbed.size() && flowerbed[i + 1] == 0;
	};

	inline bool isValidInEnding(vector<int> &flowerbed, int i) {
		return	i == flowerbed.size() - 1 && flowerbed[i] == 0 &&
				(i > 0 && flowerbed[i - 1] == 0 || flowerbed.size() == 1);
	};

	inline void update(vector<int> &flowerbed, int i, int &count) {
		flowerbed[i] = 1;
		count++;
	};

};