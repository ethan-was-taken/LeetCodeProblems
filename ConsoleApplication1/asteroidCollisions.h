#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

#include "printer.h"
#include "stopper.h"

using namespace std;

class asteroidCollisions {
public:
	static vector<int> asteroidCollision(vector<int>& asteroids) {
		
		/*							~~~~rules~~~~
		1.	"root" doesnt get popped off the stack unless it gets blown up
		2.	negatives start the stack unwind
		3.	???
		4.	profit
		*/

		if (asteroids.empty())
			return vector<int>();

		vector<int> currState;
		for (int i = 0; i < asteroids.size(); i++) {

			currState.push_back(asteroids[i]);
			if (currState.back() < 0 && currState.size() > 1)
				stackUnwind(currState);

		}

		return currState;

	};

private:
	static inline void stackUnwind(vector<int> &currState) {
		
		int top = currState.back();
		currState.pop_back();

		while (!currState.empty() && currState.back() > 0) {

			if(abs(top) > currState.back())
				currState.pop_back();
			else if (abs(top) < currState.back())
				return;
			else {
				currState.pop_back();
				return;
			}

		}
			
		currState.push_back(top);

	};

};