#pragma once
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct treeNode {
	int value;
	struct treeNode* left;
	struct treeNode* right;
};

struct Interval {
public:
	int start;
	int end;
	Interval() {}
	Interval(int start, int end) {
		this->start = start;
		this->end = end;
	}
	string toString() {
		return "[" + to_string(start) + "," + to_string(end) + "]";
	}
};

class temp {
public:
	// Add any helper functions(if needed) above.
	// NOTE: this algo is horribly inefficient, and could use some memoization
	/* E.g. digits = "235"
			1) DFS till you get to "jkl"
				a. From there return a vector, vec1, with {"j","k","l"}
			2) Iteratively go through and add {"d", "e", "f"} to vec1 vals so that you end up with the 1D array:
				{"dj", "dk", "dl",
				 "ej", "ek", "el",
				 "fj", "fk", "fl"}
				a. Call ^ vec2
				b. Deallocate memory for vec1 and return vec2
			3. Do step two but with {"a", "b", "c"}
	*/
	static vector<string> get_strings_from_nums(string digits) {

		unordered_map<int, string> keypad;
		initializeKeypad(keypad);

		vector<string> ans;
		
		dfs(keypad, ans, digits, 0, "");

		return ans;

	}

private:
	static void initializeKeypad(unordered_map<int, string> &keypad) {

		keypad['2'] = "abc";
		keypad['3'] = "def";
		keypad['4'] = "ghi";
		keypad['5'] = "jkl";
		keypad['6'] = "mno";
		keypad['7'] = "pqrs";
		keypad['8'] = "tuv";
		keypad['9'] = "wxyz";

	}

	static void dfs(unordered_map<int, string> keypad, vector<string> &ans, string digits, int index, string builder) {

		if (index >= digits.size()) {
			ans.push_back(builder);
			return;
		}
			
		builder += "-";
		string currLetters = keypad[digits[index]];
		for (int i = 0; i < currLetters.size(); i++) {

			builder.back() = currLetters[i];
			dfs(keypad, ans, digits, index + 1, builder);

		}

	}

	static void print(vector<string> ans, int index, string builder) {

		cout << "index:\t" << index << endl;
		cout << "builder:\t" << builder << endl;

		cout << "ans:\t";
		for (auto curr : ans) {
			cout << curr << ", ";
		}

		stopper();

	};

	static void stopper() {

		int stop;
		cout << "\t\t\t\t\t";
		cin >> stop;

	};


};