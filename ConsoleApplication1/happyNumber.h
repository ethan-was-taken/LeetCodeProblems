#pragma once
#include <iostream>
#include <unordered_map>

using namespace std;

class happyNumber {
public:
	bool isHappy(int n) {

		cout << n << endl;
		
		long long num = 0;

		while (n) {

			int remain = n % 10;
			n /= 10;

			num += remain * remain;

		}

		if (num == 1)
			return true;

		unordered_map<long long, int>::iterator it = check.find(num);
		if (it != check.end() && it->second == 2)
			return false;
		else if (it != check.end())
			it->second++;
		else if (it == check.end()) {
			check.insert(pair<long long, int>(num, 1));
		}

		return isHappy(num);

	};

private:
	unordered_map<long long, int> check;
};