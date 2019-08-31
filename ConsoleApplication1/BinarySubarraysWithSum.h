#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include <algorithm>
#include <random>

using namespace std;

class BinarySubarraysWithSum {
public:
	int numSubarraysWithSum(vector<int> &arr, int sum) {

		lptr = 0;
		rptr = 0;
		runningSum = 0;

		int res = 0;

		bool isDone = false;
		while (!isDone) {

			// Increase rptr until sum == runningSum or end of array
			while (isInBounds() && runningSum < sum) {



			}

			res++;

			// Increase lptr until runningSum != sum or end of array
			while (isInBounds() && runningSum == sum) {



			}


			isDone = lptr == rptr && rptr == arr.size() - 1;

		}


	}
private:
	int lptr;
	int rptr;
	int runningSum;

	inline bool isInBounds() {

	}

};