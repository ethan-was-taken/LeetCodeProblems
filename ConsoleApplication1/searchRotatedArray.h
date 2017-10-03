#include <iostream>
#include <string>
#include <vector>

using namespace std;
//Solution
class searchRotatedArray {
public:
	int search(vector<int>& nums, int target) {

		if (nums.empty())
			return -1;
			
		return modifiedBinarySearch(nums, target, 0, nums.size() - 1);
	};

private:
	int modifiedBinarySearch(vector<int>& nums, int target, int lptr, int rptr) {

		int mptr = (rptr - lptr) / 2 + lptr;

		// bass cases
		if (nums[lptr] == target)
			return lptr;
		else if (nums[rptr] == target)
			return rptr;
		else if (nums[mptr] == target)
			return mptr;
		else if (lptr >= rptr)
			return -1;
		else if(lptr >= mptr)
			return -1;
		else if (rptr <= mptr)
			return -1;

		//---------------------------------------target is bot half-------------------------------------

		//target is bot half && pivot is in upper half && we're searching bot half
		if (nums[lptr] < nums[mptr] && target <= nums[mptr] && target >= nums[lptr])
			return modifiedBinarySearch(nums, target, lptr, mptr);

		//target is bot half && pivot is in bot half   && we're searching bot half && target <= num[L]
		else if (nums[lptr] > nums[mptr] && target >= nums[mptr] && target >= nums[lptr])
			return modifiedBinarySearch(nums, target, lptr, mptr);

		//target is bot half && pivot is in bot half   && we're searching bot half && target >= num[L]
		else if (nums[lptr] > nums[mptr] && target <= nums[mptr] && target <= nums[lptr])
			return modifiedBinarySearch(nums, target, lptr, mptr);

		//---------------------------------------target is top half-------------------------------------

		//target is upp half && pivot is in lower half && we're searching upp half
		else if (nums[mptr] < nums[rptr] && target >= nums[mptr] && target <= nums[rptr] )
			return modifiedBinarySearch(nums, target, mptr, rptr);

		//target is upp half && pivot is in upp half   && we're searching upp half && target <= num[m]
		else if ( nums[mptr] > nums[rptr] && target <= nums[mptr] && target <= nums[rptr] )
			return modifiedBinarySearch(nums, target, mptr, rptr);

		//target is upp half && pivot is in upp half   && we're searching upp half && target >= num[m]
		else if ( nums[mptr] > nums[rptr] && target >= nums[mptr] && target >= nums[rptr] )
			return modifiedBinarySearch(nums, target, mptr, rptr);

		return -1;
	};
};