#include <iostream>
#include <string>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

// Solution
class threeSum_ {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {

		if (nums.empty() || nums.size() <= 2)
			return vector<vector<int>>();
			
		int numZeroes = addToNumbers(nums);
		if (numZeroes == nums.size()) {
			vector<vector<int>> toReturn1;
			vector<int> toReturn;
			toReturn.push_back(0);
			toReturn.push_back(0);
			toReturn.push_back(0);
			toReturn1.push_back(toReturn);
			return toReturn1;				
		}

		set<multiset<int>> ans;

		for (int i = 0; i < nums.size(); i++) {

			for (int j = i + 1; j < nums.size(); j++) {

				int toLookFor = -( nums[i] + nums[j] );
				int lookForIndex = contains(toLookFor, i, j);
				if (lookForIndex != -1) {
					multiset<int> toAdd;
					toAdd.insert(nums[i]);
					toAdd.insert(nums[j]);
					toAdd.insert(nums[lookForIndex]);
					ans.insert(toAdd);
				}

			}

		}

		vector<vector<int>> toReturn;

		set<multiset<int>>::iterator it;
		for (it = ans.begin(); it != ans.end(); it++) {
			vector<int> toAdd;
			for (int const& num : *it)
				toAdd.push_back(num);
				
			toReturn.push_back(toAdd);
		}
		return toReturn;
	};

private:
	int addToNumbers(vector<int>& nums) {
		int numZeroes = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 0)
				numZeroes++;
			numbers.insert(pair<int, int>(nums[i], i));
		}
		return numZeroes;
	};

	int contains(int lookFor, int index1, int index2) {
		unordered_multimap<int, int>::iterator it = numbers.find(lookFor);
		if (it != numbers.end() && it->second != index1 && it->second != index2)
			return it->second;
		return -1;
	};

	// <number, index>
	unordered_multimap<int, int> numbers;
};