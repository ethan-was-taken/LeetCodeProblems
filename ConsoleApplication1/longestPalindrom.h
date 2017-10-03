#include <iostream>
#include <map>
#include <string>

using namespace std;

class longestPalindrom {
public:
	string longestPalindrome(string str) {
		int lptr, rptr;
		int lastRightIndex = str.size();
		string toReturn = "";

		for (int i = 0; i < str.size(); i++) {

			char curr = str[i];

			lptr = i;
			rptr = findIndexOfChar(curr, lastRightIndex, str);

			while (lptr <= rptr) {

				bool isPalindrom = isPalindrome(lptr, rptr, str);
				int subStrSize = rptr - lptr + 1;
				lastRightIndex = rptr;

				// If not Palindrome and the current size of the substring is > then toReturn
				//  then there could be a Palindrome within that substring, so continue looking
				if (!isPalindrom && subStrSize > toReturn.size()) {
					lptr = i;
					rptr = findIndexOfChar(curr, lastRightIndex, str);
				}
				// If Palindrome and the current size of the substring is > toReturn
				//  then break cause the substring will only get shorter from here on out
				else if (isPalindrom && subStrSize > toReturn.size()) {
					toReturn = str.substr(lptr, subStrSize);
					break;
				}
				else
					break;

			}

			lastRightIndex = str.size();
		}

		return toReturn;
	};

private:
	//----------Functions----------
	// A better way to implement this would be to have a data structure that is essentially a hashmap mixed with an arraylist
	//  The key would be the char you're looking for and the items in the arraylist would be the indexes you can find the char at
	//  This way lookup would be between O(1) and O(n) <- worst case; instead of ALWAYS O(n)
	// O(n)
	int findIndexOfChar(char curr, int lastIndex, string str) {

		for (int i = str.size() - 1; i >= 0; i--) {
			if (str[i] == curr && i < lastIndex)
				return i;
		}

		return 0;
	};

	// O(n)
	bool isPalindrome(int lptr, int rptr, string str) {

		while (lptr <= rptr) {

			if (str[lptr] != str[rptr])
				return false;

			lptr++;
			rptr--;
		}

		return true;
	};
};