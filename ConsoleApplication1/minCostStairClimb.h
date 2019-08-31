#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class minCostStairClimb {
public:
	static int minCostClimbingStairs(vector<int>& cost) {
		
		cost.push_back(0);

		vector<int> oneCost;
		vector<int> twoCost;

		oneCost.push_back(cost[0]);
		twoCost.push_back(cost[0]);

		for (int i = 1; i < cost.size(); i++) {

			if(i - 1 >= 0)
				oneCost.push_back(min(oneCost[i - 1], twoCost[i - 1]) + cost[i]);
			if (i - 2 >= 0)
				twoCost.push_back(min(oneCost[i - 2], twoCost[i - 2]) + cost[i]);
			else
				twoCost.push_back(cost[i]);

		}

		return min(oneCost.back(), twoCost.back());

	};
};