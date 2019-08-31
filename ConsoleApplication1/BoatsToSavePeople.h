#pragma once

#include <vector>
#include <iterator>
#include <map>

using namespace std;

class BoatsToSavePeople {
public:
	int numRescueBoats(vector<int> &people, int limit) {
		
		setup(people, limit);

		for (auto currVal = this->people.begin(); currVal != this->people.end(); currVal++) {
			
			if (!currVal->second)
				continue;

			tempName(currVal);

		}

		return res;

	};

private:
	multimap<int, bool> people;
	int res;
	int currTotal;
	int limit;

	void setup(vector<int> &people, int limit) {

		for (int curr : people)
			this->people.insert(make_pair(curr, true));

		res = 0;
		currTotal = 0;
		this->limit = limit;

	};

	inline void tempName(multimap<int, bool>::iterator &currVal) {

		auto next = std::next(currVal, 1);

		int valToFind = getDelta(currVal);
		if (contains(valToFind)) {

			auto range = this->people.equal_range(valToFind);

			for (auto rangeVal = range.first; rangeVal != range.second; rangeVal++) {
				if (rangeVal->second) {
					res++;
					currVal->second = false;
					rangeVal->second = false;
					currTotal = 0;
					break;
				}
			}

		}
		else if (next != this->people.end() && currVal->first + next->first < limit)
			currTotal += currVal->first + next->first;
		else if (next != this->people.end() && currVal->first + next->first == limit)
			currTotal = 0;
		else {
			res++;
			currTotal = 0;
		}

		currVal->second = false;

	};

	inline int getDelta(multimap<int, bool>::iterator &currVal) {
		return limit - (currTotal == 0 ? currVal->first : currTotal);
	};

	inline bool contains(int valToFind) {

		auto range = this->people.equal_range(valToFind);

		for (auto rangeVal = range.first; rangeVal != range.second; rangeVal++) {
			if (rangeVal->second)
				return true;
		}

		return false;
	}

};