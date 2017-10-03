#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class mergeSortedArrays {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

		vector<int> ans;

		int i = 0;
		int j = 0;
		while(i < m && j < n) {

			cout << "-----first-----" << endl;
			cout << i << ", " << j << endl;

			ans.push_back(min(nums1[i], nums2[j]));

			if (nums1[i] < nums2[j])
				i++;
			else
				j++;

		}

		while (i < m) {
			cout << "-----second-----" << endl;

			ans.push_back(nums1[i++]);
		}

		while (j < n) {
			cout << "-----third-----" << endl;
			ans.push_back(nums2[j++]);
		}

		nums1 = ans;
		nums2 = ans;

	};

};