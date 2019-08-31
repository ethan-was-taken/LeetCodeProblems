#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "treeNode.h"

using namespace std;

class palindromeNum {
public:
	static bool isPalindrome(int x) {
		string num = to_string(x);
		reverse(num.begin(), num.end());
		return to_string(x) == num;
	};

};