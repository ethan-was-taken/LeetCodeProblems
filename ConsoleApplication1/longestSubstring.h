#include <iostream>
#include <string>
#include <map>

using namespace std;

class longestSubstring {
public:
	int lengthOfLongestSubstring(string input) {

		string longestSubString = "";
		string currSubString = "";

		// Dont even bother with the loop
		if (input.size() == 0)
			return 0;
		else if (input.size() == 1)
			return 1;

		for (unsigned int i = 0; i < input.size(); i++) {

			string curr(1, input[i]);

			// if we've found a duplicate: set i to the index of the original + 1
			//  and clear the map cause we startin over!
			multimap<string, int>::iterator it = stringContents.find(curr);
			if (it != stringContents.end()) {
				longestSubString = (longestSubString.size() < currSubString.size()) ? currSubString : longestSubString;
				i = it->second;
				currSubString.clear();
				stringContents.clear();
				continue;
			}
	
			stringContents[curr] = i;
			currSubString.append(curr);

		}

		longestSubString = (longestSubString.size() < currSubString.size()) ? currSubString : longestSubString;
		stringContents.clear();
		return longestSubString.size();

	};

private:
	// string = char in string; int = index it was found
	map<string, int> stringContents;

};