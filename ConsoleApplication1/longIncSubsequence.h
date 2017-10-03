#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>


using namespace std;

typedef std::multimap<int, int> hMap;

// FOR NOW assumes no duplicates
class longIncSubsequence {
public:
	int lengthOfLIS(vector<int>& nums) {

		addToSorted(nums);

		pair<int, int> max(INT_MIN, 0);

		for (int i = nums.size() - 1; i >= 0; i--) {
			
			cout << "----------------------------------------------------" << endl;
			cout << "currently evaluating: " << nums[i] << endl;
			stopper();

			if (nums[i] >= max.first) {

				cout << "if" << endl;
				pair<int, int> nextMax = findNextMax(nums[i]);
				cout << "nextMax: [" << nextMax.first << ", " << nextMax.second << "] " << endl;

				hMap::iterator it = sorted.find(nums[i]);
				it->second = nextMax.second + 1;

				if (it->second > max.second)
					max = pair<int, int>(it->first, it->second);

			}
			else {
				cout << "else" << endl;
				max.second++;
				hMap::iterator it = sorted.find(nums[i]);
				it->second = max.second;
				max = pair<int, int>(nums[i], max.second);
			}

			//printPairs();
			print(nums);
		}

		print(nums);

		return max.second;
	};

	


private:

	inline void stopper() {
		cout << "\t\t\t\t\t\t\t";
		int stopper;
		cin >> stopper;
	};

	//map<int, int> sorted;
	hMap sorted;

	void addToSorted(vector<int>& nums) {

		for (int i : nums)
			sorted.insert(pair<int, int>(i, 0));
		
	}

	inline pair<int, int> findNextMax(int num) {
		
		hMap::iterator it = sorted.find(num);
		it++;
		pair<int,int> tempMax(INT_MIN, 0);
		cout << "--------Find___Max---------" << endl;

		for (; it != sorted.end(); it++) {

			cout << "[" << it->first << ", " << it->second << "] ";
			
			if (it->second > tempMax.second && it->first > num) {
				
				cout << "<- in if" << endl;
						
				tempMax.second = it->second;
				tempMax.first = it->first;
			}
			else
				cout << endl;
			
			//cout << endl;
		}
		cout << "---------------------------" << endl;
		return tempMax;
	};

	void printPairs() {

		hMap::iterator it = sorted.begin();
		cout << "--------PrintPairs---------" << endl;

		for (; it != sorted.end(); it++) {
			cout << "[" << it->first << ", " << it->second << "] " << endl;
		}
		cout << "---------------------------" << endl;

	};

	void print() {

		hMap::iterator it = sorted.begin();
		cout << endl << "sorted: ";
		for (; it != sorted.end(); it++) {

			cout << "[" << it->first << ", " << it->second << "] ";

		}

		cout << endl << endl << endl;
	};

	void print(vector<int>& nums) {

		cout << endl;

		for (int i = 0; i < nums.size(); i++) 
			cout << nums[i] << " | ";
		cout << endl;

		for (int i = 0; i < nums.size(); i++)
			cout << "--" << "-+-";
		cout << endl;

		for (int i = 0; i < nums.size(); i++) {

			/*
			pair<hMap::iterator, hMap::iterator> range;
			range = sorted.equal_range(nums[i]);
			for (hMap::iterator it = range.first; it != range.second; it++) {

				if(it->second ==)

			}
			*/

			hMap::iterator it = sorted.find(nums[i]);
			

			cout << it->second << "  | ";
		}

		cout << endl << endl << endl;
	};

};