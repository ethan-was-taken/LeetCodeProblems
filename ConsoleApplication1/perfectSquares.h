#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <cmath>

using namespace std;

class perfectSquares {
public:
	int numSquares(int n) {

		//vector<int> memo(n + 1, 0); //temp
		generateSquares(n);

		//set up memo
		for (int i = 0; i < n + 1; i++)
			memo.push_back(-1);

		recurse(n);

		//print(n);

		return memo[n];
	};

private:
	inline void generateSquares(int input) {
		for (int i = 1; (int) pow(i, 2) <= input; i++)
			squares.push_back( (int) pow(i, 2) );
	};

	inline int recurse(int n) {

		//print(n);
		//cout << endl;

		if (n == 0) {
			memo[0] = 0;
			return 0;
		}

		if (memo[n] != -1) {
			//cout << "MEMO!!!!" << endl;
			return memo[n];
		}

		//cout << endl << endl << endl;

		int currMin = INT_MAX;
		for (int i = squares.size() - 1; i >= 0; i--) {
			
			if (squares[i] > n)
				continue;

			int tempMin = recurse(n - squares[i]) + 1;
			currMin = currMin > tempMin ? tempMin : currMin;
			//cout << endl << endl;
		}

		//cout << n << " currMin: " << currMin << endl;
		memo[n] = currMin;

		return memo[n];

	};

	/*
	void print(int n) {

		cout << "curr N: " << n << endl;

		for (int i = 0; i < memo.size(); i++) {
			if(i < 10)
				cout << i << "  | ";
			else
				cout << i << " | ";
		}
		cout << endl;

		for (int i = 0; i < memo.size(); i++)
			cout << "--" << "-+-";
		cout << endl;

		for (int i = 0; i < memo.size(); i++) {
			cout << (memo[i] == -1 ? 0 : memo[i]) << "  | ";
		}

	};
	*/

	//--
	vector<int> squares;
	vector<int> memo;

};