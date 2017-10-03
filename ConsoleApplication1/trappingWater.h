#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>


using namespace std;

class trappingWater {
public:
	int trap(vector<int>& height) {

		//~edge cases here~
		if (height.empty() || height.size() == 1)
			return 0;

		int lptr = 0;
		int rptr = 1;
		int totalArea = 0;

		
		while (lptr < height.size()) {

			cout << "---------------------------" << endl;

			rptr = setPointers(height, lptr);
			
			// Keeps algo from infinite loop
			if (rptr == lptr) {
				lptr++;
				continue;
			}

			int currArea = getArea(height, lptr, rptr);
			totalArea += currArea;

			cout << "totalArea: " << totalArea << endl;
			stopper();

			lptr = rptr;

		}
		
		return totalArea;

	};

private:
	void stopper() {
		int stop;
		cout << "\t\t\t\t\t";
		cin >> stop;
	}

	// Another way of doing this could be to find a valley then decrease the lptr and increase the rptr from that point, checking until they start to decrease 
	inline int setPointers(vector<int>& height, int &lptr) {

		int rptr = lptr;
		int areaUnderWater = 0;

		//------------Set RPTR------------
		// get rptr set to the next valley
		while (rptr + 1 < height.size() && height[rptr + 1] <= height[rptr]) {			
			if (height[++rptr] == 0)
				break;
		}

		while (rptr < height.size() && height[rptr] < height[lptr]) {
			/*cout << "-----" << endl;
			cout << "rptr: " << rptr << endl;
			cout << "height.size(): " << height.size() << endl;
			cout << "height[rptr]: " << height[rptr] << endl;
			cout << "height[lptr]: " << height[lptr] << endl;
			cout << "-----" << endl;*/
			rptr++;
		}

		

		// reset rptr (if necessary)
		rptr = (rptr >= height.size() ? height.size() - 1 : rptr);

		//----------End Set RPTR-----------

		

		// Set the lptr
		while (height[lptr] > height[rptr]) {
			
			lptr++;

			if (height[lptr] <= height[rptr]) {
				lptr--;
				break;
			}

		}

		//------------RESet RPTR------------
		rptr = lptr + 1;

		while (rptr < height.size() && height[rptr] < height[lptr])
			rptr++;

		// reset rptr (if necessary)
		rptr = (rptr >= height.size() ? height.size() - 1 : rptr);

		//----------End Set RPTR-----------
		

		cout << "ptrs: " << lptr << ", " << rptr << endl;

		//stopper();

		return rptr;
	};


	inline int getArea(vector<int>& height, int lptr, int rptr) {

		int mini = min(height[lptr], height[rptr]);
		
		// Subtract 1 because otherwise itll include the lptr and rptr's in the delta
		int delta = rptr - lptr - 1;

		// Get the area of the structures under the water 
		int underWaterArea = 0;
		for (int i = lptr + 1; i < rptr; i++)
			underWaterArea += height[i];

		cout << "min: " << mini << endl;
		cout << "delta: " << delta << endl;
		cout << "underWaterArea: " << underWaterArea << endl;


		return mini * delta - underWaterArea;

	};

};