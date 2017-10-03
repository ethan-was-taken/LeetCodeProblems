#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//Sliding window

class findAnagrams_438 {
public:
	vector<int> findAnagrams(string s, string p) {
		
		// Setup the characters map
		unordered_map<char, int> characters;
		for (char c : p) {
			
			if (characters.find(c) == characters.end())
				characters.insert(pair<int, int>(c, 1));
			else
				characters.find(c)->second++;

		}

		vector<int> pos;
		for (int i = 0; i < s.size(); i++) {

			

		}

		for (int in : pos) {
			cout << in << "\t";
		}

		return pos;

	};
private:
	void print(int i, char curr, int newIndex,vector<int> pos) {

		cout << "i:\t" << i << endl;
		cout << "curr:\t" << curr << endl;
		cout << "newIdx:\t" << newIndex << endl;

		for (int in : pos) {
			cout << in << "\t";
		}

		stopper();

		cout << "----------------------" << endl;
		cout << endl;	
		
	};

	void stopper() {

		int stop;
		cout << "\t\t\t\t\t";
		cin >> stop;

	};

	// returns an offset for the new value for i (if s doesnt have an anagram of p)
	// otherwise it returns 
	inline int check(unordered_map<char, int> chars, string s) {

		

	};

};