#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class AssignCookies {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {

		setup(g, s);

		setChildGreedPtrInitialPos(g, s);
		setCookiePtrInitialPos(g, s);

		for (; childGreedPtr < ub && cookiePtr < ub; childGreedPtr++, cookiePtr++) {



		}

	};

private:
	int childGreedPtr;
	int cookiePtr;
	int ub;

	void setup(vector<int>& g, vector<int>& s) {

		childGreedPtr = 0;
		cookiePtr = 0;
		ub = min(g.size(), s.size());

		sort(g.begin(), g.end());
		sort(s.begin(), s.end());

	};

	void setChildGreedPtrInitialPos(vector<int> &g, vector<int> &s) {
		while (childGreedPtr < ub && g[childGreedPtr] < s[cookiePtr])
			childGreedPtr++;
	};
		

	void setCookiePtrInitialPos(vector<int>& g, vector<int>& s) {
		while (cookiePtr < ub && s[cookiePtr] < g[childGreedPtr])
			cookiePtr++;
	};

};