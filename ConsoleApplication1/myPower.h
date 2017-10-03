#include <iostream>
#include <string>
#include <vector>

using namespace std;

class myPower {
	public:
		double myPow(double operand, int exponent) {

			double power = 1;

			if (exponent >= INT_MAX && (operand == 1 || operand == -1))
				return operand;
			else if (exponent <= INT_MIN && (operand == 1 || operand == -1))
				return 1;
			else if (exponent >= INT_MAX || exponent <= INT_MIN)
				return 0;

			// if negative
			if (exponent < 0) {
				operand = 1 / operand;
				exponent = abs(exponent);
			}

			while (exponent != 0) {

				int j = 2;
				double tempOperand = operand;

				for (; j <= exponent; j *= 2) {
					tempOperand *= tempOperand;
				}

				// We divide it by 2 because by the time the for loop 
				//  stops j will be 2x larger than the number we need
				exponent -= j / 2;
				power *= tempOperand;
			}

			if (exponent % 2 != 0)
				power *= operand;

			return power;
		};
};	