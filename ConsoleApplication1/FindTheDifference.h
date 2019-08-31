#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

#define NUM_ASCII_CHARS 128

using namespace std; 

class FindTheDifference {
public:
	char findTheDifference(string &source, string &shuffled) {

		setup();
		setCharInstances(source, shuffled);
		
		char i = 48;
		for (; i < NUM_ASCII_CHARS; i++) {

			if (sourceCharInstances[i] != shuffledCharInstances[i])
				break;

		}

		return i;

	};

private:
	vector<char> sourceCharInstances;
	vector<char> shuffledCharInstances;

	inline void setup() {
		
		vector<char> source(NUM_ASCII_CHARS, 0);
		sourceCharInstances = source;

		vector<char> shuffled(NUM_ASCII_CHARS, 0);
		shuffledCharInstances = shuffled;

	};

	inline void setCharInstances(string &source, string &shuffled) {

		int upperBound = max(source.size(), shuffled.size());
		for (int i = 0; i < upperBound; i++) {

			char sourceCurr = (i < source.size()) ? source.at(i) : NULL;
			char shuffledCurr = (i < shuffled.size()) ? shuffled.at(i) : NULL;

			if (sourceCurr != NULL)
				sourceCharInstances[sourceCurr]++;
			if (shuffledCurr != NULL)
				shuffledCharInstances[shuffledCurr]++;

		}

	};

};