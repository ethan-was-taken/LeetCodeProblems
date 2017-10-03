#pragma once
#include <unordered_set>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>   

using namespace std;

class randomizedSet {
	public:
		// Ctor
		randomizedSet() {
			srand(time(NULL));
		};

		// Dtor
		~randomizedSet() {
			delete(&dataHold);
		};

		/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
		bool insert(int val) {
			
			unordered_set<int>::iterator it = dataHold.find(val);
			dataHold.insert(val);

			return (it != dataHold.end()) ? true : false;
		};

		/** Removes a value from the set. Returns true if the set contained the specified element. */
		bool remove(int val) {
			
			unordered_set<int>::iterator it = dataHold.find(val);

			if (it == dataHold.end())
				return false;
			
			dataHold.erase(it);

			return true;
		};

		/** Get a random element from the set. */
		int getRandom() {
			
			if (dataHold.empty())
				return NULL;
			else if (dataHold.size() == 1)
				return *dataHold.begin();
			
			int random = rand() % dataHold.size() - 1;
			random = abs(random);
			unordered_set<int>::iterator it = dataHold.begin();
			advance(it, random);
			return *it;
		};

	private:
		unordered_set<int> dataHold;
};

/**
* Your RandomizedSet object will be instantiated and called as such:
* RandomizedSet obj = new RandomizedSet();
* bool param_1 = obj.insert(val);
* bool param_2 = obj.remove(val);
* int param_3 = obj.getRandom();
*/