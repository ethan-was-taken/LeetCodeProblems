#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <stack>

#include "printer.h"
#include "stopper.h"

using namespace std;

class ReverseWords_III {
public:
	string reverseWords(string &s) {

		splitIntoWords(s);

		string result;
		for (int i = 0; i < words.size(); i++) {

			string curr = words[i];

			string reversedWord = reverseWord(curr);
			result.append(reversedWord);
			result.append(i < words.size() - 1 ? " " : "");

		}

		return result;

	};

private:
	vector<string> words;

	inline void splitIntoWords(string &input) {

		char* inputArr = new char[input.size()];
		strcpy(inputArr, input.c_str());

		char *ptr = strtok(inputArr, " ");
		while (ptr) {
			words.push_back(ptr);
			ptr = strtok(NULL, " ");
		}

	};

	inline string reverseWord(string &s) {

		string res = s;
		for (int lptr = 0, rptr = s.size() - 1; lptr < s.size() / 2; lptr++, rptr--) {
			char temp = res[lptr];
			res[lptr] = res[rptr];
			res[rptr] = temp;
		}

		return res;

	};


};