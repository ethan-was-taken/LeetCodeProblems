#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std; 

class letterCombos {
public:
	vector<string> letterCombinations(string digits) {

		if (digits.size() == 0)
			return vector<string>();

		string temp = "";
		dfs(digits, 0, temp, getMapping(digits[0]));
		
		return combos;
	};

private:
	// int pos = position in originalStr && the position we're currently editing in curr
	// string curr = the string we're building to add to combos
	void dfs(string originalStr, int pos, string curr, string mapping) {

		//cout << endl;

		//Base Case
		if (pos >= originalStr.size()) {
			//cout << "adding: " << curr << endl << endl;
			combos.push_back(curr);
			return;
		}
		
		curr.append("");

		for (int i = 0; i < mapping.size(); i++) {
			curr.replace(pos, 1, mapping.substr(i,1));
			//cout << "curr: " << curr << endl;
			if (pos + 1 < originalStr.size())
				dfs(originalStr, pos + 1, curr, getMapping(originalStr.at(pos + 1)));
			else
				dfs(originalStr, pos + 1, curr, "");
			//cout << "after" << endl << endl;
		}

	};

	string getMapping(char ch) {
		cout << "ch: " << ch << endl;
		switch (ch) {
			case '0':	return " ";
			case '1':	return "";
			case '2':	return "abc";
			case '3':	return "def";
			case '4':	return "ghi";
			case '5':	return "jkl";
			case '6':	return "mno";
			case '7':	return "pqrs";
			case '8':	return "tuv";
			case '9':	return "wxyz";
			default:	return "";
		}

	};

	//------Global Vars------
	vector<string> combos;
};