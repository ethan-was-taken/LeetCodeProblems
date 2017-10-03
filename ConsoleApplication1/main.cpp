#include "stdafx.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>

#include "temp.h"
#include "printer.h"

using namespace std;

int main() {	

	treeNode* root = new treeNode();
	treeNode* ptr = root;
	ptr->value = 6;

	ptr->left = new treeNode();
	ptr->right = new treeNode();
	ptr->left->value = 4;
	ptr->right->value = 8;

	ptr = ptr->left;
	ptr->left = new treeNode();
	ptr->right = new treeNode();
	ptr->left->value = 3;
	ptr->right->value = 5;

	ptr = ptr->left;
	ptr->left = new treeNode();
	ptr->left->value = 2;
	

	ptr = root->right;
	ptr->left = new treeNode();
	ptr->right = new treeNode();
	ptr->left->value = 7;
	ptr->right->value = 9;

	printer::postorder(root);

	//------------------------------------------------------------------------
	cout << "starting" << endl;
	clock_t Start = clock();

	auto ans = temp::get_strings_from_nums("234");
	
	for (auto curr : ans) {
		cout << curr << ", ";
	}
	
	//cout << "ans:\t\t" << ans->value << endl;
	
	
	cout << "took: " << (clock() - Start) << " ms" << endl << endl;
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
				if (currLine[j] == ']') {
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
};*/


