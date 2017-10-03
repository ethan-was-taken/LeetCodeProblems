#pragma once
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class wordPattern_ {
public:
	bool wordPattern(string pattern, string str) {

		unordered_map<char, string> relationshipForward;
		unordered_map<string, char> relationshipBackward;
		vector<string> words = getWords(str);

		if (words.size() != pattern.size())
			return false;

		print(words);

		int i = 0;
		for (char curr : pattern) {

			if (relationshipForward.find(curr) != relationshipForward.end() && relationshipForward[curr] != words[i]) {
				cout << "----failing----" << endl;
				cout << "curr:\t" << curr << endl;
				cout << "relationship[curr]:\t" << relationshipForward[curr] << endl;
				cout << "words[i]:\t" << words[i] << endl;
				print(relationshipForward);
				return false;
			}
			if (relationshipBackward.find(words[i]) != relationshipBackward.end() && relationshipBackward[words[i]] != curr) {
				cout << "----failing----" << endl;
				return false;
			}

			cout << "----adding----" << endl;
			cout << "curr:\t" << curr << endl;
			cout << "words[i]:\t" << words[i] << endl;
			relationshipForward.insert(pair<char, string>(curr, words[i]));
			relationshipBackward.insert(pair<string, char>(words[i], curr));
			print(relationshipForward);
			i++;

		}

		print(relationshipForward);

		return true;

	};

private:
	vector<string> getWords(string &str) {

		vector<string> words;

		int start = 0;
		for (int i = 1; i < str.size(); i++) {

			while (i < str.size() && str[i] != ' ')
				i++;
			
			int length = i - start;
			string curr = str.substr(start, length);
			words.push_back(curr);

			start = i + 1;

		}

		return words;

	};

	inline void print(vector<string> words) {

		for (string curr : words) {
			if(curr == " ")
				cout << "_" << setw(5);
			else
				cout << curr << setw(5);
		}
		cout << endl;

		stopper();

	}

	inline void print(unordered_map<char, string> relationship) {

		unordered_map<char, string>::iterator it = relationship.begin();
		for (; it != relationship.end(); it++) {
			cout << "[" << it->first << ", " << it->second << "]" << setw(5);
		}
		cout << endl;

		stopper();

	}

	void stopper() {

		int stop;
		cout << "\t\t\t\t\t";
		cin >> stop;

	};

};