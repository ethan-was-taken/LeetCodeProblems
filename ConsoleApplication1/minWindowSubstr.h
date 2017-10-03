#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

/*
1.	put T in hashmap where second is num instances & first is the character
2.	set lptr and rptr;
		increment rptr till you get T's hashmap is equal to S's
		set minWindow (if possible)
3.	increment lptr (and remove the characters that are no longer in the window) until
	 T's hashmap is NOT equal to S's
4.	STOP LOOPING when rptr is at the end of T AND T's hashmap is NOT equal to S's
*/

class minWindowSubstr {
public:
	string minWindow(string s, string t) {

		add(tHash, 0, t.size(), t);

		int rptr = 0;
		int min = INT_MAX;
		pair<int, int> minPtrs(-1, -1);

		for (int lptr = 0; lptr < s.size(); lptr++) {

			incrementRptr(lptr, rptr, s);
			incrementLptr(lptr, rptr, s);

			if (rptr == s.size() - 1 && !isEqual(sHash))
				break;

			int currMin = rptr - lptr + 1;

			if (currMin >= t.size() && currMin < min && check(s.substr(lptr, rptr - lptr + 1))) {
				min = currMin;
				minPtrs = pair<int, int>(lptr, rptr);
			}


			// Remove an instance of whatever it was pointing to
			if (lptr + 1 < s.size() && sHash.find(s[lptr]) != sHash.end())
				sHash.find(s[lptr])->second--;

			rptr++;

		}

		if (minPtrs.first == -1 || minPtrs.second == -1)
			return "";

		return s.substr(minPtrs.first, minPtrs.second - minPtrs.first + 1);

	};

private:
	inline void add(unordered_map<char, int> &toAdd, int beg, int end, string str) {

		for (int i = beg; i < end; i++) {

			char c = str[i];
			if (toAdd.find(c) != toAdd.end())
				toAdd.find(c)->second++;
			else
				toAdd.insert(pair<char, int>(c, 1));

		}

	};

	inline void incrementRptr(int lptr, int &rptr, string s) {

		for (int i = rptr; i < s.size(); i++) {

			// If the current char isnt in the T string, dont add it to S's hashtable
			if (tHash.find(s[i]) == tHash.end()) {
				continue;
			}

			if (sHash.find(s[i]) != sHash.end())
				sHash.find(s[i])->second++;
			else
				sHash.insert(pair<char, int>(s[i], 1));

			if (isEqual(sHash)) {
				rptr = i;
				break;
			}

		}

		// Just in case rptr goes over the max size
		rptr = (rptr >= s.size()) ? s.size() - 1 : rptr;

	};

	inline void incrementLptr(int &lptr, int rptr, string s) {

		for (int i = lptr; i <= rptr; i++) {

			// If the current char isnt in the T string, dont remove it to S's hashtable
			if (tHash.find(s[i]) == tHash.end()) {
				continue;
			}

			if (sHash.find(s[i])->second - 1 >= tHash.find(s[i])->second) {
				sHash.find(s[i])->second--;
			}
			else {
				lptr = i;
				break;
			}

		}

	};

	inline bool isEqual(unordered_map<char, int> s_Hash) {

		unordered_map<char, int>::iterator it = tHash.begin();
		for (; it != tHash.end(); it++) {

			unordered_map<char, int>::iterator curr = s_Hash.find(it->first);
			if (curr == s_Hash.end()) {
				return false;
			}

			int numInstances = curr->second;
			if (numInstances < it->second) {
				return false;
			}

		}

		return true;

	};

	inline bool check(string s) {

		unordered_map<char, int> s_Hash;
		for (int i = 0; i < s.size(); i++) {

			if (tHash.find(s[i]) == tHash.end()) {
				continue;
			}

			char c = s[i];
			if (s_Hash.find(c) != s_Hash.end())
				s_Hash.find(c)->second++;
			else
				s_Hash.insert(pair<char, int>(c, 1));

		}

		return isEqual(s_Hash);

	}

	unordered_map<char, int> sHash;
	unordered_map<char, int> tHash;

};