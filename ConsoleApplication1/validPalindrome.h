#pragma once
#include <iostream>
#include <regex>

using namespace std;

class validPalindrome {
public:
	bool isPalindrome(string s) {

		int size = s.size();

		if (size == 1)
			return true;

		for (int i = 0, j = size - 1; i <= size / 2 && j >= size / 2; i++, j--) {


			while (!isValid(s[i]) && i < size - 1)
				i++;

			while (!isValid(s[j]) && j > 0)
				j--;

			if (!equalIgnoreCase(s[i], s[j]))
				return false;

		}

		return true;

	};

private:
	inline bool equalIgnoreCase(int first, int second) {

		//if first is lowercase, make it uppercase
		if (first >= 97 && first <= 122)
			first -= 32;

		//if second is lowercase, make it uppercase
		if (second >= 97 && second <= 122)
			second -= 32;

		// if first is 0-9 || A-Z
		if (first >= 48 && first <= 57 || first >= 65 && first <= 90) {
			if (first == second)
				return true;
		}

		return (!isValid(first) && !isValid(second)) ? true : false;

	};

	inline bool isValid(int first) {

		if (first >= 48 && first <= 57 ||
			first >= 65 && first <= 90 ||
			first >= 97 && first <= 122) {

			return true;
		}

		return false;

	};

};