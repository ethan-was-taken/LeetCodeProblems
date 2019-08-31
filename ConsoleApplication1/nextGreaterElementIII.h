#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include "stopper.h"

using namespace std;

class nextGreaterElementIII {
public:
	int nextGreaterElement(int n) {

		vector<int> vals = addValues(n);
		
		for (int rptr = vals.size() - 1; rptr > 0; rptr--) {

			for (int lptr = rptr; lptr > 0; lptr--) {

				if (vals[rptr] > vals[lptr]) {
					iter_swap(vals.begin() + i, vals.begin() + j);
					sort(vals.begin() + lptr + 1, vals.end());
					return arrayToInt(vals);
				}

			}

		}

		sort(vals.begin() + 1, vals.end());
		int next = nextLargest(vals);

		if (vals[0] < vals[next]) {
			iter_swap(vals.begin(), vals.begin() + next);
			sort(vals.begin() + 1, vals.end());
			return arrayToInt(vals);
		}

		return -1;

	};

private:
	vector<int> addValues(int n) {
		vector<int> vals;
		while (n > 0) {
			vals.push_back(n % 10);
			n /= 10;
		}
		reverse(vals.rbegin(), vals.rend());
		return vals;
	};

	int nextLargest(vector<int> &arr) {
		for (int i = 1; i < arr.size(); i++) {
			if (arr[0] < arr[i])
				return i;
		}
		return -1;
	};

	int arrayToInt(vector<int> arr) {

		reverse(arr.rbegin(), arr.rend());

		long long modifier = 1;
		long long toReturn = 0;
		for (int curr : arr) {
			toReturn += modifier * curr;
			modifier *= 10;
		}

		if (toReturn >= INT_MAX)
			return -1;

		return (int) toReturn;

	};


};