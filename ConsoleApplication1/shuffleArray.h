#pragma once
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>   

using namespace std;

class shuffleArray {
	public:
		shuffleArray(vector<int> nums) {
			originalArray = nums;
			currArray = originalArray;
		}

		/** Resets the array to its original configuration and return it. */
		vector<int> reset() {
			currArray = originalArray;
			return originalArray;
		}

		/** Returns a random shuffling of the array. */
		vector<int> shuffle() {
			
			srand(time(NULL));

			for (int i = 0; i < currArray.size(); i++) {

				int random = rand() % currArray.size();

				int temp = currArray[i];
				currArray[i] = currArray[random];
				currArray[random] = temp;

			}

			return currArray;
		};

	private:
		vector<int> originalArray;
		vector<int> currArray;
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(nums);
* vector<int> param_1 = obj.reset();
* vector<int> param_2 = obj.shuffle();
*/

/*
// Init an array with set 1, 2, and 3.
int[] nums = { 1,2,3 };
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();
*/