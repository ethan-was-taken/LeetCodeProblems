#pragma once

#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class ReorganizeString {
public:
	string reorganizeString(string str) {

		vector<string> storage;
		for (char curr : str)
			storage.push_back(string(curr, 1));
		
		sort(storage.begin(), storage.end());

		string res;
		int lptr = 0;
		int mptr = storage.size() / 2;

		for (; mptr < storage.size(); lptr++, mptr++) {

			if (storage[lptr] == storage[mptr])
				return str;

			res += storage[lptr] + storage[mptr];

		}


	};
};