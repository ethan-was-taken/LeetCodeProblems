#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class mostWater_11 {
public:
	int maxArea(vector<int>& height) {

		int lptr = 0;
		int rptr = height.size() - 1;

		int largestArea = 0;

		while (lptr < rptr) {

			int currArea = findArea(height, lptr, rptr);
			if (currArea > largestArea)
				largestArea = currArea;

			if (height[lptr] > height[rptr])
				rptr--;
			else
				lptr++;
		}

		return largestArea;
	};

private:
	inline int findArea(vector<int>& height, int lptr, int rptr) {

		int delta = (rptr - lptr == 0) ? 1 : (rptr - lptr);
		int smallestHeight = (height[rptr] < height[lptr]) ? height[rptr] : height[lptr];

		return delta * smallestHeight;
	};
};