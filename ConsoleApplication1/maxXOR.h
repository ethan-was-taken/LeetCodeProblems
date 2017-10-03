#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <bitset>


using namespace std;

class maxXOR {
public:
	int findMaximumXOR(vector<int>& nums) {

		vector<bitset<32>> butts;
		for (int curr : nums) {
			bitset<32> bits(curr);
			butts.push_back(bits);
		}

		for (int i = 0; i < butts.size(); i++) {

			string str = butts[i].to_string();
			/*int index = str.find_first_of("1");
			str = str.substr(index);*/

			str = str.substr(str.size() - 6);

			cout << setw(10) << str << "\t" << setw(10) << nums[i] << endl;
		}



		return -1;

	};

private:


};