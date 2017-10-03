#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class findKthLarge {
public:
	int findKthLargest(vector<int>& nums, int k) {

		priority_queue<int> sorted;

		for (int curr : nums) 
			sorted.push(curr);
		
		for (int i = k; k > 1; k--)
			sorted.pop();

		return sorted.top();
	};

private:


};