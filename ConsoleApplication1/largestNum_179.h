#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#include "printer.h"
#include "stopper.h"

using namespace std; 

struct CustomCompare {

	inline bool operator()(const string &str1, const string &str2) {
		if (str1[0] != str2[0])
			return str1[0] > str2[0];
		return createString(str1, str2) > createString(str2, str1);
	};

	inline string createString(const string &str1, const string &str2) {
		string total;
		total.reserve(str1.size() + str2.size());
		total.append(str1);
		total.append(str2);
		return total;
	};

};


class largestNum_179 {
public:
	static string largestNumber(vector<int> &nums) {
		
		if (nums.empty())
			return "";

		vector<string> stringNums;
		int lengthToReserve = 0;
		for (int curr : nums) {
			string toAdd = to_string(curr);
			lengthToReserve += toAdd.size();
			stringNums.push_back(toAdd);
		}

		sort(stringNums.begin(), stringNums.end(), CustomCompare());

		string ans;
		ans.reserve(lengthToReserve);
		for (string curr : stringNums)
			ans.append(curr);

		return (ans[0] == '0') ? "0" : ans;

	};

};
