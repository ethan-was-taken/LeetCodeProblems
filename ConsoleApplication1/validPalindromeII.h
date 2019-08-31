#pragma once
#include <iostream>
#include "stopper.h"

using namespace std;

class validPalindromeII {
public:
	static bool validPalindrome(string s) {
		
		int lptr = 0;
		int rptr = s.size() - 1;
		for (; lptr < s.size() / 2; lptr++, rptr--) {

			if (s[lptr] != s[rptr]) {

				int length = rptr - lptr;

				if (isPalindrome(s.substr(lptr, length)))
					break;
				else if (isPalindrome(s.substr(lptr + 1, length)))
					break;
				else
					return false;

			}

		}

		return true;

	};

private:
	static bool isPalindrome(string s) {

		int lptr = 0;
		int rptr = s.size() - 1;
		for (; lptr < s.size() / 2; lptr++, rptr--) {
			if (s[lptr] != s[rptr])
				return false;
		}

		return true;

	};
	

};