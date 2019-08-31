#pragma once
#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <bitset>
#include <string>
#include <stack>
#include <unordered_set>

#include "printer.h"
#include "stopper.h"

using namespace std;

class contigiousArray {
public:
	static int findMaxLength(vector<int>& nums) {

		int zeroCount = 0;
		int oneCount = 0;

		for (int i = 0; i < nums.size(); i++) {
			zeroCount = nums[i] == 0 ? zeroCount + 1 : zeroCount;
			oneCount = nums[i] == 1 ? oneCount + 1 : oneCount;
		}

		// if min value (which will either be 1 or 0), is at the 
		//   end of the array: subtract 1 from it
		int mini = min(zeroCount, oneCount);
		fixup(nums, zeroCount, oneCount, mini);

		return mini * 2;

	};

private:
	static inline void fixup(vector<int>& nums, int zeroCount, int oneCount, int &mini) {
		if (nums.size() <= 2 || zeroCount == oneCount)
			return;
		if (zeroCount == mini && nums.back() == 0)
			mini--;
		else if (oneCount == mini && nums.back() == 1)
			mini--;
	};

};
