#pragma once
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class MaxWidthRamp {
public:
	int maxWidthRamp(vector<int> &vals) {
		return maxWidthRampNaive(vals);
	};

private:
	int maxWidthRampNaive(vector<int> &vals) {

		int maxWidth = INT_MIN;

		for (int i = 0; i < vals.size(); i++) {

			for (int j = vals.size()-1; j > i; j--) {

				int currWidth = (vals[i] <= vals[j]) ? (j - i) : 0;
				maxWidth = max(maxWidth, currWidth);

				if (currWidth > 0)
					break;

			}

		}

		return maxWidth == INT_MIN ? 0 : maxWidth;

	};

};