#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

class XofAKind {
public:
	bool hasGroupsSizeX(const vector<int> &deck) {
		
		setupCardInstances(deck);
		setGroupSize();

		if (groupSize == 1)
			return false;

		for (pair<int, int> curr : cardInstances) {
			if (curr.second % groupSize != 0)
				return false;
		}

		return true;

	};

private:
	unordered_map<int, int> cardInstances;
	int groupSize;

	inline void setupCardInstances(const vector<int> &deck) {
		for (int i = 0; i < deck.size(); i++)
			cardInstances[deck[i]]++;
	};

	inline void setGroupSize() {

		int temp = INT_MAX;
		groupSize = INT_MAX;
		for (pair<int, int> curr : cardInstances) {
			groupSize = min(groupSize, curr.second);
			temp = min(temp, lcm(groupSize, curr.second));
		}
		int x = 0;
	};

	inline int lcm(int a, int b) {
		int temp = gcd(a, b);
		return temp ? (a / temp * b) : 0;
	};

	inline int gcd(int a, int b) {

		while (true) {

			if (a == 0)
				return b;
			b %= a;

			if (b == 0)
				return a;
			a %= b;

		}

	};

};
