#include <iostream>
#include <string>

#include <sstream>

using namespace std;


class fractionToDec {
	public:
		string fractionToDecimal(int numerator, int denominator) {

			double result = (double) numerator / denominator;

			ostringstream ss;
			ss << result;

			cout << ss.str() << endl;

			string res = fixRepeating(ss.str());

			return res;

		};

	private:
		string fixRepeating(string input) {
			bool isRepeating = false;
			bool pastPoint= false;

			int pointPos = 0;

			// goes up to the second to last decimal pos so that we dont go out of bounds
			for (int i = (input.size() - 2); i >= 0; i--) {

				cout << "curr:\t" << input[i] << endl;
				cout << "curr+1:\t" << input[i - 1] << endl << endl;

				if (input[i] == input[i - 1]) {
					isRepeating = true;
					pointPos = i - 1;
					continue;
				}
				else if (input[i] != input[i - 1]) {
					break;
				}
				
			}

			if (isRepeating) {

				string repeatNum(1,input[pointPos + 1]);

				input = input.substr(0, pointPos);

				input.append("(");
				input.append(repeatNum);
				input.append(")");

			}

			return input;

		};
};