#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

class permInString {
public:
	bool checkInclusion(string s1, string s2) {

		if (s1.empty() || s2.empty() || s2.size() < s1.size())
			return false;

		// Add chars from s1 to a hashmap
		add(str1, 0, s1.size(), s1);
		
		// Add the same amount of chars in s1 from s2 to a hashmap
		add(str2, 0, s1.size(), s2);
	
		int rptr = s1.size() - 1;
		for (int i = 0; i < s2.size(); i++) {

			if (isEqual())
				return true;

			// Add one instance of rptr + 1 to str2
			addSingle(rptr, s2);
			// Remove one instance of i to str2
			removeSingle(i, s2);

		}

		return false;

	};

private:
	void stopper() {
		int stop;
		cout << "\t\t\t\t\t";
		cin >> stop;
	};

	inline void add(unordered_map<char, int> &toAdd, int beg, int end, string str) {

		for (int i = beg; i < end; i++) {

			char c = str[i];
			if (toAdd.find(c) != toAdd.end())
				toAdd.find(c)->second++;
			else
				toAdd.insert(pair<char, int>(c, 1));

		}

	};

	inline bool isEqual() {

		unordered_map<char, int>::iterator it = str1.begin();
		for (; it != str1.end(); it++) {

			unordered_map<char, int>::iterator curr = str2.find(it->first);

			if (curr == str2.end())
				return false;

			int numInstances = curr->second;

			if (numInstances != it->second)
				return false;

		}

		return true;

	};

	inline void addSingle(int &rptr, string s2) {

		rptr++;
		if (rptr >= s2.size())
			return;

		char c = s2[rptr];
		if (str2.find(c) != str2.end())
			str2.find(c)->second++;
		else
			str2.insert(pair<char, int>(c, 1));

	};

	inline void removeSingle(int lptr, string s2) {

		char c = s2[lptr];
		if (str2.find(c)->second == 1)
			str2.erase(c);
		else
			str2.find(c)->second--;

	};

	void print(string curr, string str, int lptr, int rptr) {

		cout << "looking at: " << curr << endl;
		cout << "s2: " << str << endl;
		cout << "-----------------------------------" << endl;


		//---------------------------------------------
		// char - s1
		unordered_map<char, int>::iterator it = str1.begin();
		for (; it != str1.end(); it++) {
			cout << it->first << " | ";
		}
		cout << endl;
		// seperator
		it = str1.begin();
		for (; it != str1.end(); it++) {
			cout << "--+-";
		}
		cout << endl;
		// number of instances of each char - s1
		it = str1.begin();
		for (; it != str1.end(); it++) {
			cout << it->second << " | ";
		}
		cout << endl;
		cout << endl;
		//---------------------------------------------
		// char - s2
		it = str2.begin();
		for (; it != str2.end(); it++) {
			cout << it->first << " | ";
		}
		cout << endl;
		
		// seperator
		it = str2.begin();
		for (; it != str2.end(); it++) {
			cout << "--+-";
		}
		cout << endl;

		// number of instances of each char - s2
		it = str2.begin();
		for (; it != str2.end(); it++) {
			cout << it->second << " | ";
		}
		cout << endl;
		cout << endl;
		cout << endl;

	}

	void printSingle(unordered_map<char, int> toAdd) {

		//---------------------------------------------
		// char - s1
		unordered_map<char, int>::iterator it = toAdd.begin();
		for (; it != toAdd.end(); it++) {
			cout << it->first << " | ";
		}
		cout << endl;
		// seperator
		it = toAdd.begin();
		for (; it != toAdd.end(); it++) {
			cout << "--+-";
		}
		cout << endl;
		// number of instances of each char - s1
		it = toAdd.begin();
		for (; it != toAdd.end(); it++) {
			cout << it->second << " | ";
		}
		cout << endl;
		cout << endl;
		cout << endl;


	}


	unordered_map<char, int> str1;
	unordered_map<char, int> str2;


};