#pragma once

#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class DailyTemps {
public:
	vector<int> dailyTemperatures(vector<int> &temps) {
		
		result.resize(temps.size(), 0);

		for (int i = temps.size() - 1; i >= 0; i--) {

			updateMostRecentTemperatureDate(temps[i], i);
			
			int nextHottestDay = findNextHottestDayIndex(i, temps[i]);
			result[i] = nextHottestDay - i;

		}

		return result;

	};

private:
	unordered_map<int, int> mostRecentTemperatureDate;
	vector<int> result;

	void updateMostRecentTemperatureDate(int currTemp, int index) {
		mostRecentTemperatureDate[currTemp] = index;
	};

	int findNextHottestDayIndex(int currIndex, int currTemp) {
		int nextHottestDay = INT_MAX;
		auto temperature = mostRecentTemperatureDate.begin();
		for (; temperature != mostRecentTemperatureDate.end(); temperature++) {
			if (temperature->first > currTemp && nextHottestDay >= currIndex)
				nextHottestDay = min(temperature->second, nextHottestDay);
		}
		return nextHottestDay == INT_MAX ? currIndex : nextHottestDay;
	};

};