#pragma once
#include <iostream>
#include <vector>

using namespace std;

class moveZeroes_283 {
	public:
		moveZeroes_283() {
			zeroPtr = 0;
			nonZeroPtr = 0;
		};

		void moveZeroes(vector<int> &nums) {
			moveZeroesToBack(nums);
		};

	private:
		vector<int> nums;
		int zeroPtr;
		int nonZeroPtr;

		void moveZeroesToBack(vector<int> &nums) {

			this->nums = nums;
			setPointers();

			reorderNums();

			nums = this->nums;

		};

		inline void setPointers() {
			setZeroPtrToNextZero();
			setNonZeroPtrToNextNonZero();
		};

		inline void setZeroPtrToNextZero() {
			while (zeroPtr < nums.size() - 1 && nums[zeroPtr] != 0)
				zeroPtr++;
		};

		inline void setNonZeroPtrToNextNonZero() {
			// We need to make sure that nonZeroPtr is always after the zeroPtr
			while (nonZeroPtr < nums.size() - 1 && nums[nonZeroPtr] == 0 || nonZeroPtr < zeroPtr)
				nonZeroPtr++;
		};

		inline void reorderNums() {

			while (arePointersInBounds()) {
				swap(zeroPtr, nonZeroPtr);
				setPointers();
			}

			if (nums[nonZeroPtr] != 0)
				swap(zeroPtr, nonZeroPtr);

		};

		inline bool arePointersInBounds() {
			bool isZeroPtrInBounds = zeroPtr != nums.size() - 1;
			bool isNonZeroPtrInBounds = nonZeroPtr != nums.size() - 1;
			return isZeroPtrInBounds && isNonZeroPtrInBounds;
		};

		inline void swap(int zeroPtr, int nonZeroPtr) {
			int temp = nums[zeroPtr];
			nums[zeroPtr] = nums[nonZeroPtr];
			nums[nonZeroPtr] = temp;
		};

};