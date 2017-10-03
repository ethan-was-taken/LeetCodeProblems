#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>

#define LENGTH 10

using namespace std;

class repeatedDNASequences {
public:
	vector<string> findRepeatedDnaSequences(string s) {

		cout << "s.size():\t" << s.size() << endl;

		if (s.size() < LENGTH)
			return vector<string>();

		unordered_map<string, int> sequences;
		for (int i = 0; i < s.size() - LENGTH + 1; i++) {
			string curr = s.substr(i, LENGTH);
			sequences[curr]++;
		}

		vector<string> ans;

		unordered_map<string, int>::iterator it = sequences.begin(); 
		for (; it != sequences.end(); it++) {

			cout << it->first << setw(10) << it->second << endl;

			if (it->second < 2)
				continue;

			ans.push_back(it->first);

		}

		return ans;

	};


};