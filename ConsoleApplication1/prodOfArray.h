#include <iostream>
#include <vector>

using namespace std;

class prodOfArray {
public:
	vector<int> productExceptSelf(vector<int>& input) {// change back to nums later
		vector<int> output(input.size(), 1);
	
		int lastPos = input.size();

		// This gets us the left multipliers
		output[lastPos - 2] = input[lastPos - 1];
		for (int i = lastPos - 2; i > 0; i--)
			output[i - 1] *= input[i] * output[i];

		for (int j = 0; j < output.size(); j++)
			cout << output[j] << " ";
		cout << endl;

		// This multiplies the left multipliers by the right multipliers
		int prevMultiplier = input[0];
		for (int i = 1; i < lastPos; i++) {
			cout << "output[i]: " << output[i] << endl;
			cout << "prevMultiplier: " << prevMultiplier << endl << endl;
			output[i] *= prevMultiplier;
			prevMultiplier = input[i] * prevMultiplier;
		}

		return output;
	}
};