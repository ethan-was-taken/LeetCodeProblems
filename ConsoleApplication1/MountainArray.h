#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class MountainArray {
public:
	bool validMountainArray(vector<int> &peakHeights) {

		if (peakHeights.size() <= 2)
			return false;

		setup(peakHeights);

		for (int i = 0; i < peakHeights.size() - 1; i++) {

			setHasPeak(i);

			if (isInvalidAscent(i))
				isGoingUp = false;
			else if (isInvalidDescent(i))
				return false;

		}

		return hasPeak;

	};

private:
	bool hasPeak;
	bool isGoingUp;
	vector<int> *peakHeights;

	void setup(vector<int> &peakHeights) {
		this->peakHeights = &peakHeights;
		isGoingUp = true;
		hasPeak = false;
	};

	inline void setHasPeak(int i) {
		if (hasPeak || i == 0)
			return;
		else if (peakHeights->at(i - 1) < peakHeights->at(i) && peakHeights->at(i) > peakHeights->at(i + 1))
			hasPeak = true;
	};

	inline bool isInvalidAscent(int i) {
		return isGoingUp && peakHeights->at(i) >= peakHeights->at(i + 1);
	};

	inline bool isInvalidDescent(int i) {
		return !isGoingUp && peakHeights->at(i) <= peakHeights->at(i + 1);
	};

};