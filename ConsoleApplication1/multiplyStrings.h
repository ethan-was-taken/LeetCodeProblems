#pragma once
#include <iostream>
#include <string>
#include <vector>

#define BASE 10

using namespace std;

class multiplyStrings {
public:
	// https://en.wikipedia.org/wiki/Multiplication_algorithm#Long_multiplication
	string multiply(string num1, string num2) {

		string product(num1.size() + num2.size(), '0');

		for (int i = num1.size() - 1; i >= 0; i--) {

			int carry = 0;

			for (int j = num2.size() - 1; j >= 0; j--) {

				int prod = (num1[i] - '0') * (num2[j] - '0') + (product[i + j + 1] - '0') + carry;
				carry = prod / BASE;
				product[i + j + 1] = prod % BASE + '0';

			}

			product[i] += carry;

		}

		// Trim the leading zero's if there are any
		return trim(product);

	};

private:
	inline string trim(string str) {

		int pos = str.find_first_not_of("0");
		if (pos != string::npos)
			return str.substr(pos);
		
		return "0";

	};

};