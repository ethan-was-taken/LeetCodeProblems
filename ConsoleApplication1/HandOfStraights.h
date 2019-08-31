#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>

#define MAP_ITER map<int, int>::iterator

using namespace std;

class HandOfStraights {
public:
	bool isNStraightHand(vector<int> &hand_, int groupSize) {

		if (hand_.size() % groupSize != 0)
			return false;

		setup(hand_);
		
		vector<int> grouping;
		MAP_ITER resetPoint = hand.begin();
		MAP_ITER i = hand.begin();
		while (i != hand.end()) {
			
			auto curr = *i;

			if (grouping.empty() || curr.first == grouping.back() + 1) {

				grouping.push_back(curr.first);
				availableValues[curr.first]--;
				updateResetPoint(resetPoint, i);

				if (availableValues[curr.first] == 0)
					availableValues.erase(curr.first);

				// After every reset (i.e. whenever toAdd is cleared) 'i' needs to get set back to the 
				//  first key with a non-zero value
				if (grouping.size() == groupSize) {
					grouping.clear();
					i = resetPoint;
					continue;
				}

			}
			else
				return false;
			
			i++;

		}

		return availableValues.empty() ? true : false;

	};

private:
	map<int, int> hand;
	unordered_map<int, int> availableValues;

	inline void setup(vector<int> &hand_) {
		for (auto curr : hand_) {
			hand[curr]++;
			availableValues[curr]++;
		}
	};

	inline void updateResetPoint(MAP_ITER &resetPoint, MAP_ITER &i) {
		auto curr = *i;
		if (availableValues[curr.first] == 0)
			resetPoint = ++i;
	};

};