#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class sortColor {
public:
	void sortColors(vector<int>& nums) {

		int numRed = 0;
		int numWhite = 0;
		int numBlue = 0;

		for (int i = 0; i < nums.size(); i++) {

			if (nums[i] == 0)
				numRed++;
			else if (nums[i] == 1)
				numWhite++;
			else if (nums[i] == 2)
				numBlue++;

		}

		for (int i = 0; i < numRed; i++)
			nums[i] = 0;
		for (int i = numRed; i < numRed + numWhite; i++)
			nums[i] = 1;
		for (int i = numRed + numWhite; i < nums.size(); i++)
			nums[i] = 2;

	};

};