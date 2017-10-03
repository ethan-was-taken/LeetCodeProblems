#pragma once
#include <iostream>
#include <vector>

using namespace std;

class plusOne_66 {
public:
	vector<int> plusOne(vector<int>& digits) {

		int i = digits.size() - 1;
		int carry = 1;				// Carry is 1 because thats how much we're increasing digits by

		for (; i >= 0; i--) {

			digits[i] += carry;

			if (digits[i] < 10)
				break;
						
			carry = digits[i] - 9;
			digits[i] -= 10;

		}

		if (i < 0 && carry > 0)
			digits.insert(digits.begin(), carry);
		
		return digits;

	};

private:
	void print(vector<int>& digits, int carry, int index) {
		
		cout << "---------------------------------------" << endl;
		cout << "carry:\t" << carry << endl;

		for (int i = 0; i <= index; i++) {

			if (i != index)
				cout << " \t";
			else
				cout << carry << "\t";

		}
		cout << endl;

		for (int i : digits) {
			cout << i << "\t";
		}
		cout << endl;



		int stop;
		cout << "\t\t\t\t\t";
		cin >> stop;

	}
};