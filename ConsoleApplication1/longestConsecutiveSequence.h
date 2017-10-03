#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;


class longestConsecutiveSequence {
public:
	int longestConsecutive(vector<int>& nums) {

		// Handle edge cases
		if (nums.empty())
			return 0;
		else if (nums.size() == 1)
			return 1;

		for (int i = 0; i < nums.size(); i++) 
			hashMap.insert(pair<int, int>(nums[i], 1));
		
		// Another edge case
		if (hashMap.size() == 1)
			return 1;

		int longestSequence = INT_MIN;
		unordered_map<int, int>::iterator it = hashMap.begin();
		for (; it != hashMap.end(); it++) {
			
			// If a given numbers longest sequence is > 1 then we've already been to 
			//  that number (by going through other numbers) so skip it 
			if (it->second != 1)
				continue;
			
			int longestSequenceUp = goingUp(it->first);
			int longestSequenceDown = goingDown(it->first, longestSequenceUp);

			int seqSize = setSequenceLength(longestSequenceDown, longestSequenceUp, it->first);

			if (seqSize > longestSequence)
				longestSequence = seqSize;

		}

		return longestSequence;

	};

private:
	inline int goingUp(int currNum) {

		int i = currNum + 1;
		while (hashMap.find(i) != hashMap.end())
			i++;

		if (i == currNum + 1)
			return 0;
		
		return i - currNum;

	};

	inline int goingDown(int currNum, int longestSequenceUp) {

		int i = currNum - 1;
		while (hashMap.find(i) != hashMap.end())
			i--;

		if (i == currNum - 1)
			return 0;

		return currNum - i;

	};

	inline int setSequenceLength(int longestSequenceDown, int longestSequenceUp, int currNum) {
		
		// If both are zero theres no point in continuing because the longest 
		//  total sequence is defaulted to 1
		if (longestSequenceUp == 0 && longestSequenceDown == 0)
			return 1;

		int longestTotalSequence = longestSequenceUp + longestSequenceDown;
		if (longestSequenceUp != 0 && longestSequenceDown != 0)
			longestTotalSequence -= 1;
		
		int upperBound = longestSequenceUp + currNum;
		int lowerBound = currNum - longestSequenceDown;

		for (int i = lowerBound + 1; i < upperBound; i++)
			hashMap.find(i)->second = longestTotalSequence;
		
		return longestTotalSequence;
	}

	//---------------Global Vars---------------
	// first  int == number
	// secind int == current longest consecutive sequence for that num
	unordered_map<int, int> hashMap;

};