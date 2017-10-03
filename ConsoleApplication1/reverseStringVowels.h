#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_set>

using namespace std;

class reverseStringVowels {
public:
	// Assumes string s is only lowercase
	string reverseVowels(string s) {

		unordered_set<char> vowels;
		add(vowels);

		//vector<bool> visited(s.size(), false);

		for (int i = 0, j = s.size() - 1; i < j; i++, j--) {

			// increase i until its pointing to a vowel
			while (i < j && vowels.find(s[i++]) == vowels.end());
			i--;

			// decrease j until its pointing to a vowel
			while (i < j && vowels.find(s[j--]) == vowels.end());
			j++;

			/*if (isInvalid(vowels, visited, s, i, j))
				break;*/

			swap(s, i, j);
			//visited[i] = visited[j] = true;

			cout << "s:\t" << s << endl;

			int stop;
			cout << "\t\t\t\t\t";
			cin >> stop;
			cout << endl;


		}

		return s;

	};

private:
	inline void add(unordered_set<char> &vowels) {
		vowels.insert('a');
		vowels.insert('e');
		vowels.insert('i');
		vowels.insert('o');
		vowels.insert('u');
		vowels.insert('A');
		vowels.insert('E');
		vowels.insert('I');
		vowels.insert('O');
		vowels.insert('U');
	};

	inline void swap(string &s, int i, int j) {
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	};

	inline bool isInvalid(unordered_set<char> &vowels, vector<bool> &visited, string &s, int i, int j) {
		return visited[i] || visited[j] || vowels.find(s[i]) == vowels.end() || vowels.find(s[j]) == vowels.end();
	};

};