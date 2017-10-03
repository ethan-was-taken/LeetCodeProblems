#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class buySellStock {
public:
	int maxProfit(vector<int>& prices) {
		
		if (prices.empty() || prices.size() == 1)
			return 0;

		int max = 0;
		int currMax = 0;
		int lptr = 0;

		for (int i = 1; i < prices.size(); i++) {

			if (prices[i] < prices[lptr]) {
				lptr = i;
				continue;
			}

			currMax = prices[i] - prices[lptr];

			max = (max < currMax) ? currMax : max;

		}

		return max;

	};

	void stopper() {

		int stop;
		cout << "\t\t\t\t\t";
		cin >> stop;

	};

};