#include <string>
#include <vector>

using namespace std;

class searchForRange {
	public:
		vector<int> searchRange(vector<int>& nums, int target) {

			if (nums.size() == 0)
				return getNegitiveVector();
							
			int leftIndex = leftBinarySearch(nums, target);
			if (leftIndex == -1)
				return getNegitiveVector();

			int rightIndex = rightBinarySearch(nums, target);
			if (rightIndex == -1)
				return getNegitiveVector();
			

			vector<int> toReturn;
			toReturn.push_back(leftIndex);
			toReturn.push_back(rightIndex);

			return toReturn;
		};

	private:

		inline vector<int> getNegitiveVector() {
			vector<int> toReturn;
			toReturn.push_back(-1);
			toReturn.push_back(-1);
			return toReturn;
		}

		inline int leftBinarySearch(vector<int>& nums, int target) {

			int low = 0;
			int high = nums.size() - 1;

			while (low <= high) {

				int mid = (low + high) / 2;

				if (nums[mid] >= target)
					high = mid - 1;
				else
					low = mid + 1;

			}

			return (nums[low] != target) ? -1 : low;
		};

		inline int rightBinarySearch(vector<int>& nums, int target) {

			int low = 0;
			int high = nums.size() - 1;

			while (low <= high) {

				int mid = (low + high) / 2;

				if (nums[mid] > target)
					high = mid - 1;
				else
					low = mid + 1;

			}
			
			low--;
			if (low == -1)
				return -1;
			else if (nums[low] != target)
				return -1;

			return low;
		};
};