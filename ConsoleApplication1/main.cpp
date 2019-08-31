#include "stdafx.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include <algorithm>
#include <random>

#include "MinASCIIDeleteSum.h"
#include "NonDecreasingArray.h"
//#include "PreorderRecovery.h"
#include "ComboSumIII.h"
//#include "printer.h"


using namespace std;

int randomfunc(int j) {
	return rand() % j;
};

void randomPairs(vector<vector<int>> &in) {

	for (int i = 0; i < 7; i++) {

		int one = randomfunc(100);
		int two = randomfunc(100);

		vector<int> temp;
		temp.push_back(one / 10);
		temp.push_back(two / 10);

		sort(temp.begin(), temp.end());

		in.push_back(temp);
	}

};

string getRandString(int sizeUpperBound) {

	string res = "";
	//int ub = randomfunc(sizeUpperBound);
	int ub = sizeUpperBound;

	for (int i = 0; i < ub; i++) {
		char randChar = randomfunc(26) + 'a';
		res += randChar;
	}

	return res;

};
/* 
	1
-	2
--	3
--	4
-	5
--	6
--	7
*/
int main() {

	//------------------------------------------------------------------------
	cout << "starting" << endl;
	clock_t Start = clock();

	/*PreorderRecovery temp;
	temp.recoverFromPreorder("1-2--3--4-5--6--7");*/

	ComboSumIII temp;
	//auto res = temp.combinationSum3(3, 7);
	auto res = temp.combinationSum3(2, 18);

	cout << "took: " << (clock() - Start) << " ms" << endl << endl;

	//printer::print(ans);

	//------------------------------------------------------------------------

	return 0;

}






























/*
vector<vector<int>> getInput() {

	string filename = "C:\\Users\\ethan\\Desktop\\input.txt";
	ifstream file(filename.c_str(), ios::in);
	vector<vector<int>> send;

	//--------------------------------------
	// get input
	string currLine;
	while (!file.eof()) {

		getline(file, currLine);

		for (int i = 1; i < currLine.size(); ) {

			vector<int> temp;

			for (int j = i; j < currLine.size(); j++) {
				if (currLine{j} == '}') {
					string str = currLine.substr(i, j - i);
					int num = atoi(str.c_str());
					i = j + 3;
					temp.push_back(num);
					//break;
				}
			}

			send.push_back(temp);

		}
	}

	cout << send.size() << endl;
	// end of get input
	//--------------------------------------
	return send;

};

vector<int> getRandomArray(int size) {

	srand(time(NULL));

	vector<int> toReturn;
	for (int i = 0; i < size; i++)
		toReturn.push_back(rand() % 100);

	return toReturn;
};

vector<int> getRandomBinaryArray(int size) {

	srand(time(NULL));

	vector<int> toReturn;
	for (int i = 0; i < size; i++)
		toReturn.push_back(rand() % 2);

	return toReturn;

};

void rotateArray(vector<int> &nums, int startPos) {

	vector<int> temp;
	int j = 0;
	for (int i = startPos; j < nums.size(); j++) {

		temp.push_back(nums{i});
		i++;
		i = (i >= nums.size()) ? 0 : i;

	}

	nums = temp;

};
*/