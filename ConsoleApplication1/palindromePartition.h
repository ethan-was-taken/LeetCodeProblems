#pragma once
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

#include "printer.h"

using namespace std;

class palindromePartition {
public:
	vector<vector<string>> partition(string s) {

		vector<vector<string>> toReturn;

		for (int i = 1; i < s.size(); i++) {

			string firstHalf = s.substr(0, i);
			string secondHalf = s.substr(i);
			vector<string> currPath;

			dfs(firstHalf, currPath);
			dfs(secondHalf, currPath);

			if (!currPath.empty())
				toReturn.push_back(currPath);

			printer print;
			print.print(toReturn);
			cout << "--------------------------------------" << endl;

		}

		return toReturn;

	};

private:
	inline bool dfs(string first, vector<string> &path) {

		if (isPalindrome(first)) {
			
			path.push_back(first);
			partitions.insert(first);
			return true;

		}

		if (first.size() == 1) {
			return false;
		}

		print(first, path);

		for (int i = 1; i < first.size(); i++) {

			string firstHalf = first.substr(0, i);
			string secondHalf = first.substr(i);

			cout << "1st:\t" << firstHalf << endl;
			cout << "2nd:\t" << secondHalf << endl;

			if(dfs(firstHalf, path))
				dfs(secondHalf, path);

		}

	};

	inline bool isPalindrome(string first) {

		if (first.size() == 1) {
			return true;
		}

		int j = first.size() - 1;
		for (int i = 0; i < first.size(); i++) {
			if (first[i] != first[j])
				return false;
			j--;
		}
		
		return true;

	};

	void print(string first,/* string second, */vector<string> path) {

		cout << "first: " << first << endl;

		cout << "path:\t";
		for (string s : path) {
			cout << s << "\t";
		}
		cout << endl;

		int stop;
		cout << "\t\t\t\t\t";
		cin >> stop;

	}

	// -----Global Vars-----
	unordered_set<string> partitions;
};