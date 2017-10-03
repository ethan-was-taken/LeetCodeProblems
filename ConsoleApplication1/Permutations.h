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
		vector<vector<int>> permute(vector<int>& nums) {

			generate(nums.size(), nums);

			return hold;

		};

	private:
		inline void generate(int size, vector<int>& nums) {

			if (size == 1) {
				hold.push_back(nums);
				return;
			}

			for (int i = 0; i < size - 1; i++) {
				generate(size - 1, nums);

				if (size % 2 == 0)
					swap(nums, i, size - 1);
				else
					swap(nums, 0, size - 1);

			}

			generate(size - 1, nums);

		};

		inline void swap(vector<int>& nums, int index1, int index2) {
			int temp = nums[index1];
			nums[index1] = nums[index2];
			nums[index2] = temp;
		};

		vector<vector<int>> hold;
};