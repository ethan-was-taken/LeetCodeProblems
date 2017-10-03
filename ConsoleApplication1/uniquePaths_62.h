#pragma once
#include <iostream>
#include <vector>

using namespace std;

// Solution
class uniquePaths_62 {
public:
	int uniquePaths(int m, int n) {

		// set up memo
		setupMemo(m, n);

		for (int row = m - 2; row >= 0; row--) {
			
			// memo[row][col] is equal to the #unique paths going right + #unique paths going down
			for (int col = n - 2; col >= 0; col--)
				memo[row][col] = memo[row][col + 1] + memo[row + 1][col];

		}

		return memo[0][0];

	};

private:
	void setupMemo(int m, int n) {

		for (int i = 0; i < m; i++) {

			vector<int> temp;

			for (int j = 0; j < n; j++) {

				if (j == (n - 1))
					temp.push_back(1);
				else if (i == (m - 1))
					temp.push_back(1);
				else
					temp.push_back(0);

			}

			memo.push_back(temp);

		}

	};

	//-----GlobalVars-----
	vector<vector<int>> memo;

};