#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class wordBreak_ {
public:
	bool wordBreak(string s, vector<string>& wordDict) {

		if (wordDict.size() == 1)
			return s == wordDict[0];

		addToDict(wordDict);

		vector<bool> dp(s.size() + 1, false);
		//dp[0] = true;
		int i = 0;
		for (; i < s.size(); i++) {

			string left = s.substr(0, i);
			string right = s.substr(i, s.size() - i);


			unordered_set<string>::iterator findLeft = dict.find(left);
			unordered_set<string>::iterator findRight = dict.find(right);

			if (findLeft != dict.end() && dfs(right, dp, i)) {
				dp[i] = true;
				break;
			}

		}

		return dp[i];
	}

private:

	inline bool dfs(string str, vector<bool>& dp, int index) {

		/*cout << "str " << str << endl;
		cout << "index: " << index << endl;*/

		if (dp[index]) {
			//cout << "true" << endl;
			return true;
		}
		//cout << 1 << endl;
		if (str.size() == 0) {
			dp[index] = false;
			return false;
		}

		unordered_set<string>::iterator findRight = dict.find(str);
		if (findRight != dict.end()) {
			dp[index] = true;
			return true;
		}

		for (int i = 1; i < str.size(); i++) {

			string left = str.substr(0, i);
			string right = str.substr(i, str.size() - i);

			cout << "l: " << left << endl;
			cout << "r: " << right << endl;
			cout << "index: " << index << endl;
			cout << "dp[index]: " << dp[index] << endl << endl;

			unordered_set<string>::iterator findLeft = dict.find(left);

			//bool ans = false;
			if (findLeft != dict.end() && dfs(right, dp, i)){
				break;
			}
			else
				dp[i] = false;
		}

		return dp.back();
	}

	void addToDict(vector<string>& wordDict) {
		for (string str : wordDict)
			dict.insert(str);
		dict.insert("");
	}

	unordered_set<string> dict;
	//vector<bool> *dp;
};
