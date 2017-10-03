#pragma once
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std; 

class generateParens {
// Paren = Parenthesis
public:
	vector<string> generateParenthesis(int n) {
		
		if (n == 0)
			return ans;

		dfs("", 0, 0, n);

		return ans;
	};


private:
	void dfs(string curr, int openCount, int closedCount, int parenLimit) {

		// Bass Case
		if (openCount >= parenLimit && closedCount == openCount) {
			ans.push_back(curr);
			return;
		}

		if (openCount + 1 <= parenLimit)
			dfs(curr + "(", openCount + 1, closedCount, parenLimit);
		
		if (closedCount < openCount)
			dfs(curr + ")", openCount, closedCount + 1, parenLimit);
		
	};
	vector<string> ans;
};