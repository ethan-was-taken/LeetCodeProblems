#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

//Solution
class jumpGame {
	public:
		
		bool canJump(vector<int>& nums) {

			if (nums.empty()) {
				cout << "-3" << endl;
				return true;
			}
			else if (nums.size() == 1) {
				cout << "-2" << endl;
				return true;
			}
			else if (nums.size() > 0 && nums[0] == 0) {
				cout << "-1" << endl;
				return false;
			}

			if (!findZeroes(nums)) {
				cout << "-1" << endl;
				return true;
			}

			unordered_map<int, int>::iterator it;
			for (it = zeroPositions.begin(); it != zeroPositions.end(); it++) {

				int zeroSeriesSize = it->first + it->second;


				for (int i = (it->first - 1); i >= 0; i--) {

					int maxJumpIndex = nums[i] + i;

					cout << "it->first: " << it->first << endl;
					if (maxJumpIndex >= nums.size() - 1) {
						if (++it != zeroPositions.end()) 
							break;
						cout << "1" << endl;
						return true;
					}
					else if (maxJumpIndex >= zeroSeriesSize) {
						break;
					}

					else if (i == 0) {
						cout << "3" << endl;
						return false;
					}
					
				}
			}
			cout << "4" << endl;
			return true;
		};

	private:
		//--------FUNCTIONS---------
		// returns true if 1 or more zeroes were found in nums
		// false otherwise
		inline bool findZeroes(vector<int>& nums) {

			cout << "-----------------findZeroes-----------------" << endl;

			bool hasZeroes = false;
			for (int i = 0; i < nums.size(); ) {

				int countZero = 0;
				int j = i;
				while (nums[j++] == 0 && j < nums.size())
					countZero++;
				// then we've fount a series of zeroes
				if (countZero != 0) {
					zeroPositions[i] = countZero;
					cout << i << ": " << nums[i] << " " << countZero << endl;
					hasZeroes = true;
				}
				// at the very least i has been incremented by one since j gets incremented by 1
				i = j;
			}
			cout << endl;

			return hasZeroes;
		};

		//--------GlobalVars--------
		// first int is the position of the zero, second int is the length of consecutive zeroes; 
		// eg: [1,0,0,0,5] would have a single entry: <1,3>
		unordered_map<int, int> zeroPositions;

};