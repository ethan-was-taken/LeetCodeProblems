#include "pch.h"
#include "..\ConsoleApplication1\MaxLengthPairChain.h"
#include <Random>

TEST(MaxLengthPairChainTest, emptyVector) {
	
	vector<vector<int>> vec;

	MaxLengthPairChain sut;
	auto res = sut.findLongestChain(vec);

	EXPECT_EQ(res, 0);

}

TEST(MaxLengthPairChainTest, singleVector) {

	srand(NULL);
	

	vector<vector<int>> vec = { {(rand() % 10 + 50), (rand() % 100 + 100) } };

	MaxLengthPairChain sut;
	auto res = sut.findLongestChain(vec);

	EXPECT_EQ(res, 1);

}

TEST(MaxLengthPairChainTest, validInput1) {

	// setup
	vector<int> a = { 0, 7 };
	vector<int> b = { 1, 2 };
	vector<int> c = { 3, 4 };
	vector<int> d = { 5, 6 };
	vector<int> e = { 7, 8 };
	vector<int> f = { 7, 12 };
	vector<int> g = { 8, 9 };
	vector<int> h = { 8, 12 };
	vector<int> i = { 10, 11 };


	vector<vector<int>> input;
	input.push_back(a);
	input.push_back(b);
	input.push_back(c);
	input.push_back(d);
	input.push_back(e);
	input.push_back(f);
	input.push_back(g);
	input.push_back(h);
	input.push_back(i);

	
	MaxLengthPairChain sut;
	auto res = sut.findLongestChain(input);

	EXPECT_EQ(res, 5);

}

TEST(MaxLengthPairChainTest, validInput2) {

	// (See vector g and h) Tests that a pair with two possible, different lengthed chains 
	//   will still output the correct val
	vector<int> g = { 8, 10 };		//2 - needs to be smaller than h
	vector<int> h = { 8, 11 };		//3 - needs to be LARGER than g
	vector<int> i = { 11, 22 };		//1
	vector<int> a = { 12, 13 };		//2
	vector<int> b = { 14, 17 };		//1

	vector<vector<int>> input;
	input.push_back(a);
	input.push_back(h);
	input.push_back(b);
	input.push_back(i);
	input.push_back(g);

	MaxLengthPairChain sut;
	auto res = sut.findLongestChain(input);

	EXPECT_EQ(res, 3);

}

TEST(MaxLengthPairChainTest, inputWithDuplicates) {

	// setup
	vector<int> e = { 7, 8 };	// 4
	vector<int> f = { 7, 8 };	// 4
	vector<int> g = { 8, 13 };	// 2
	vector<int> h = { 8, 11 };	// 3
	vector<int> i = { 10, 11 }; // 3
	vector<int> a = { 12, 13 }; // 2
	vector<int> b = { 14, 17 }; // 1

	vector<vector<int>> input;
	input.push_back(a);
	input.push_back(h);
	input.push_back(e);
	input.push_back(f);
	input.push_back(b);
	input.push_back(i);
	input.push_back(g);

	MaxLengthPairChain sut;
	auto res = sut.findLongestChain(input);

	EXPECT_EQ(res, 4);

}

TEST(MaxLengthPairChainTest, inputWithNegatives) {

	// setup
	vector<int> g = { -6,-4 };
	vector<int> h = { -6,10 };
	vector<int> i = { -3,-1 };
	vector<int> a = { 0,1 };
	vector<int> b = { 2,3 };

	vector<vector<int>> input;
	input.push_back(a);
	input.push_back(h);
	input.push_back(b);
	input.push_back(i);
	input.push_back(g);

	MaxLengthPairChain sut;
	auto res = sut.findLongestChain(input);

	EXPECT_EQ(res, 6);

}