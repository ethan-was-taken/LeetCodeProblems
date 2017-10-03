#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Solution
class romanToInteger {
	public:
		romanToInteger() {
			romanNumerals.insert(pair<char, int>('I',		1));
			romanNumerals.insert(pair<char, int>('V',		5));
			romanNumerals.insert(pair<char, int>('X',		10));
			romanNumerals.insert(pair<char, int>('L',		50));
			romanNumerals.insert(pair<char, int>('C',		100));
			romanNumerals.insert(pair<char, int>('D',		500));
			romanNumerals.insert(pair<char, int>('M',		1000));
		};

		int romanToInt(string s) {

			int ans = 0;
			for (int i = 0; i < s.size(); i++) {
				
				unordered_map<char, int>::iterator it1 = romanNumerals.find(s[i]);
				if (i == s.size() - 1) {
					ans += it1->second;
					break;
				}

				unordered_map<char, int>::iterator it2 = romanNumerals.find( s[i + 1] );
				if (it1->second < it2->second) {
					ans += it2->second - it1->second;
					i++;
					continue;
				}

				ans += it1->second;
			}
			return ans;
		};

	private:
		unordered_map<char, int> romanNumerals;

};