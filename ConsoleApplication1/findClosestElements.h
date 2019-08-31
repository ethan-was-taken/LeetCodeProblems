#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct fuckkk {
	int val;
	int delta;
	fuckkk(int val, int delta) : val(val), delta(delta) {};
};

struct fuckkk_compare {
	inline bool operator()(const fuckkk &first, const fuckkk &second) const {
		return first.delta < second.delta;
	};
};

class findClosestElements {
public:
	static vector<int> findKClosestElements(vector<int>& arr, int k, int x) {
		if (arr.size() == 1)
			return arr;

		vector<fuckkk> deltaArr;
		for (int i = 0; i < arr.size(); i++)
			deltaArr.push_back(fuckkk(arr[i], abs(arr[i] - x)));

		stable_sort(deltaArr.begin(), deltaArr.end(), fuckkk_compare());

		vector<int> toReturn;
		for (int i = 0; i < k; i++) {
			toReturn.push_back(deltaArr[i].val);
		}

		sort(toReturn.begin(), toReturn.end());

		return toReturn;
	};

private:
	static void stopper() {

		int stop;
		cout << "\t\t\t\t\t";
		cin >> stop;

	};

};