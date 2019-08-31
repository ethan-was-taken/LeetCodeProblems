#include "pch.h"
#include "..\ConsoleApplication1\LongestLengthFibSubSequence.h"
#include <Random>

TEST(LongestLengthFibSubSequenceTest, test1) {

	vector<int> input = { 1,2,3,4,5,6,7,8 };
	LongestLengthFibSubSequence sut;
	auto res = sut.lenLongestFibSubseq(input);

	EXPECT_EQ(res, 5);

}