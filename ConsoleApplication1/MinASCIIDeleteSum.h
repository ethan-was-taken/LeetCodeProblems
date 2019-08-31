#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <random>
#include <string>
#include <algorithm>

using namespace std;

struct CharInstanceInfo {
	string* pointer;
	int numInstances;
	int posInStr;
};

class MinASCIIDeleteSum {
public:
	/*
	s1 = d e l e t e
	s2 = l e e t

	1. remove all non shared characters between s1 and s2

	i = 0 1 2 3 4
		e l e t e
		l e e t _

	2. at i = 0 we can do 1 of 3 things:
			1. remove e
			2. remove l
			3. nothing
		in this case we remove e because it costs less to remove e than it does l

		i = 0 1 2 3
			l e t e
			l e e t

	3. now s1[0] == s2[0], so we increase i until we get to a point were s1[i] != s2[i]
		repeat steps 2 & 3 until we finish


	*/
	int minimumDeleteSum(string s1, string s2) {

		if (s1.empty() || s2.empty())
			return getAsciiSum(s1, s2);

		setup(s1, s2);

		getNumInstancesMap();
		removeUnsharedCharacters(input1, input2);
		removeUnsharedCharacters(input2, input1);
		makeInputStringsEqual();		

		return result;

	};

private:
	unsigned long result;
	string input1;
	string input2;
	map<char, CharInstanceInfo> &instances;

	int getAsciiSum(string &s1, string &s2) {
		int toReturn = 0;
		int ub = (int) max(s1.size(), s2.size());
		for (int i = 0; i < ub; i++)			
			toReturn += i < s1.size() ? s1[i] : s2[i];
		return toReturn;
	};

	void setup(string &s1, string &s2) {
		result = 0;
		input1 = s1;
		input2 = s2;
	};

	void getNumInstancesMap() {
		int ub = (int) max(input1.size(), input2.size());
		for (int i = 0; i < ub; i++) {
			updateNumInstancesMap(input1, i);
			updateNumInstancesMap(input2, i);
		}
	};

	inline void updateNumInstancesMap(string &input, int i) {
		if (i < input.size()) {
			instances[input[i]].pointer = &input;
			instances[input[i]].posInStr = i;
			instances[input[i]].numInstances++;
		}
	};

	void removeUnsharedCharacters(string &in1, string &in2) {

		for (auto curr : instances) {
			if (curr.second.numInstances == 1) {
				in1.erase(curr.second.posInStr, 1);
				result += curr.first;
			}
		}

	};	

	void makeInputStringsEqual() {
		
		for (int i = 0; i < max(input1.size(), input2.size()); ) {

			// need to handle when i is at a valid index for 1 string but not the other
			if (input1.size() < i || input2.size() < i)
				result += eraseHangingChar(i);
			else if (input1[i] != input2[i])
				result += eraseSmallerCharFromInputAt(i);
			else
				i++;			

		}

	};

	inline char eraseHangingChar(int index) {
		
		char toReturn = input1.size() < index ? input2[index] : input1[index];

		if (input1.size() < index)
			input2.erase(index, 1);
		else
			input1.erase(index, 1);

		return toReturn;
		
	};

	inline char eraseSmallerCharFromInputAt(int index) {

		char toReturn = input1[index] < input2[index] ? input1[index] : input2[index];

		if (input1[index] < input2[index])
			input1.erase(0, 1);
		else if (input2[index] < input1[index])
			input2.erase(0, 1);
			
		return toReturn;

	};

};