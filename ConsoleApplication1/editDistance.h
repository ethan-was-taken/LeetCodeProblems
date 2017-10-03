#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

#define DELETE_MOD 1
#define INSERT_MOD 1
#define REPLACE_MOD 1

using namespace std;

// https://web.stanford.edu/class/cs124/lec/med.pdf
class editDistance {
public:
	int minDistance(string word1, string word2) {
		
		if (word1.empty())
			return word2.size() * INSERT_MOD;
		if (word2.empty())
			return word1.size() * INSERT_MOD;

		vector<vector<int>> minEdit = initialize(word1.size(), word2.size());

		for (int i = 1; i <= word1.size(); i++) {

			for (int j = 1; j <= word2.size(); j++) {

				int deleteCost = minEdit[i - 1][j] + DELETE_MOD;
				int insertCost = minEdit[i][j - 1] + INSERT_MOD;
				int replaceCost = minEdit[i - 1][j - 1] + replaceModifier(word1, word2, i - 1, j - 1);

				cout << "del: " << deleteCost << endl;
				cout << "ins: " << insertCost << endl;
				cout << "rep: " << replaceCost << endl;

				minEdit[i][j] = minimum(deleteCost, insertCost, replaceCost);

				print(minEdit, word1, word2);

			}

		}
		cout << endl << "------------------" << endl;
		print(minEdit, word1, word2);


		return minEdit[word1.size()][word2.size()];

	};

private:
	void print(vector<vector<int>> mat, string w1, string w2) {
		
		cout << "  ~ ";
		for (char c : w1)
			cout << c << " ";
		cout << endl;

		for (int i = 0; i < mat.size(); i++) {
			if (i > 0)
				cout << w2[i - 1] << " ";
			else
				cout << "~ ";
			for (int j : mat[i]) 
				cout << j << " ";
			cout << endl;
		}
		cout << endl << endl;
	};

	vector<vector<int>> initialize(int w1, int w2) {

		vector<vector<int>> toReturn;

		for (int i = 0; i <= w1; i++) {

			vector<int> temp;

			for (int j = 0; j <= w2; j++) {

				if (i == 0)
					temp.push_back(j);
				else if (j == 0)
					temp.push_back(i);
				else
					temp.push_back(-1);

			}

			toReturn.push_back(temp);

		}

		return toReturn;

	};

	inline int replaceModifier(string word1, string word2, int i, int j) {

		cout << "w1[i]: " << word1[i] << endl;
		cout << "w2[j]: " << word2[j] << endl;

		if (word1[i] == word2[j])
			return 0;
		return REPLACE_MOD;
	};

	inline int minimum(int delCost, int insCost, int repCost) {
		return min(min(delCost, insCost), repCost);
	};

};