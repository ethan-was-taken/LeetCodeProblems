#pragma once
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class maxDistanceArrays {
public:
	int maxDistance(vector<vector<int>>& arrays) {
		if (arrays.size() < 2)
			return 0;
		/*
		1.	Pass over matrix and look at first and last element of each array.
				If an element is > than the first or second largest element, store/replae whatever its 
				larger than. Make sure to also store the row it is found in. Do the same thing for the 
				smallest elements.
		2.	After 1st pass you now have the two smallest elements and the two largest elements. Check if the 
				smallest and largest elements are in the same array. 
				If they are find the delta between the largest element and the second smallest element. Also 
				find the delta between the second largest element and the smallest element.
				If they are NOT in the same array, then find the delta between the largest and smallest element
		3.	Return whatever has the largest delta
		*/
		
		// 1st int -> #
		// 2nd int -> row the # was found in
		pair<int, int> largest(INT_MIN, INT_MIN), secondLargest(INT_MIN, INT_MIN);
		pair<int, int> smallest(INT_MAX, INT_MAX), secondsmallest(INT_MAX, INT_MAX);

		for (int i = 0; i < arrays.size(); i++) {

			vector<int> currRow = arrays[i];

			if (currRow.back() >= largest.first) {
				secondLargest = largest;
				largest.first = currRow.back();
				largest.second = i;
			}
			else if (currRow.back() >= secondLargest.first) {
				secondLargest.first = currRow.back();
				secondLargest.second = i;
			}

			if (currRow.front() <= smallest.first) {
				secondsmallest = smallest;
				smallest.first = currRow.front();
				smallest.second = i;
			}
			else if (currRow.front() <= secondsmallest.first) {
				secondsmallest.first = currRow.front();
				secondsmallest.second = i;
			}

		}

		int delta = 0;

		if (largest.second == smallest.second) {
			int tempDel1 = abs(largest.first - secondsmallest.first);
			int tempDel2 = abs(secondLargest.first - smallest.first);
			delta = (tempDel1 > tempDel2) ? tempDel1 : tempDel2;
		}
		else {
			delta = abs(largest.first - smallest.first);
		}

		return delta;
	};

};