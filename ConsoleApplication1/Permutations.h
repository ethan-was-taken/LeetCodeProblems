#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <cmath>

using namespace std;
// Based off Heaps algorithm: https://en.wikipedia.org/wiki/Heap%27s_algorithm
// Solution
class Permutations {
public:
	static vector<vector<int>> permute(vector<int>& nums) {

		vector<vector<int>> hold;

		generate(hold, nums.size(), nums);

		return hold;

	};

private:
	static inline void generate(vector<vector<int>> &hold, int size, vector<int>& nums) {

		if (size == 1) {
			hold.push_back(nums);
			return;
		}

		for (int i = 0; i < size - 1; i++) {

			generate(hold, size - 1, nums);

			if (size % 2 == 0)
				swap(nums, i, size - 1);
			else
				swap(nums, 0, size - 1);

		}

		generate(hold, size - 1, nums);

	};

	static inline void swap(vector<int>& nums, int index1, int index2) {
		int temp = nums[index1];
		nums[index1] = nums[index2];
		nums[index2] = temp;
	};

};