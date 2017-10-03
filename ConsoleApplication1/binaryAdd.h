#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class binaryAdd {
public:
	string addBinary(string a, string b) {

		if (a.empty())
			return b;
		if (b.empty())
			return a;

		string res = "";

		if (a.size() > b.size())
			res = addNums(a, b);
		else
			res = addNums(b, a);

		return removeLeadingZeros(res);

	};

private:
	inline string addNums(string op1, string op2) {

		op2 = fixOperand(op2, op1.size());

		string result;
		result.resize(op1.size() + 1);

		char carry = '0';

		for (int i = op1.size() - 1; i >= 0; i--) {

			// If: both are 1 
			if (op1[i] == op2[i] && op1[i] == '1') {
				result[i + 1] = add('0', carry);
				carry = '1';
			}
			// If: op1[i] XOR op2[i]
			else if ((op1[i] == '1' && op2[i] == '0') || (op1[i] == '0' && op2[i] == '1')) {
				result[i + 1] = add('1', carry);
				carry = (carry == '1') ? '1' : '0';
			}
			// If: both are 0
			else {
				result[i + 1] = add('0', carry);
				carry = '0';
			}

		}

		result[0] = carry;

		return result;

	};

	inline char add(char op1, char carry) {
		if (op1 == '1' && carry == '1' || op1 == '0' && carry == '0')
			return '0';
		return '1';
	};

	inline string fixOperand(string op, int size) {

		string toReturn;
		toReturn.resize(size);
		int index = op.size() - 1;
		for (int i = toReturn.size() - 1; i >= 0; i--) {
			char toAdd = (index < 0) ? '0' : op[index];
			toReturn[i] = toAdd;
			index--;
		}

		return toReturn;

	}

	inline string removeLeadingZeros(string result) {
		int i = -1;
		while (result[++i] == '0');
		result = result.substr(i, result.size() - i);

		if (result.empty())
			return "0";

		return result;
	};

};