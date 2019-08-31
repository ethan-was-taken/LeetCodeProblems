#include "pch.h"
#include "..\ConsoleApplication1\NumConsecutiveDiff.h"
#include <Random>

TEST(NumConsecutiveDiff_GTest, testSingleDigitInput) {

	NumConsectiveDiff sut;

	for (int i = 0; i < 10; i++) {
		
		auto res = sut.numsSameConsecDiff(1, i);
		EXPECT_EQ(res.size(), 10);

		for (int j = 0; j < 10; j++)
			EXPECT_EQ(res[j], j);

	}

}

TEST(NumConsecutiveDiff_GTest, testValid_1) {

	vector<int> correctAns = { 181, 292, 707, 818, 929 };

	NumConsectiveDiff sut;
	auto res = sut.numsSameConsecDiff(3, 7);
	EXPECT_EQ(res.size(), correctAns.size());

	for (int i = 0; i < res.size(); i++) {
		EXPECT_EQ(res[i], correctAns[i]);
	}

}

TEST(NumConsecutiveDiff_GTest, testValid_3) {

	vector<int> correctAns = { 10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98 };

	NumConsectiveDiff sut;
	auto res = sut.numsSameConsecDiff(2, 1);
	EXPECT_EQ(res.size(), correctAns.size());

	for (int i = 0; i < res.size(); i++) {
		EXPECT_EQ(res[i], correctAns[i]);
	}

}

TEST(NumConsecutiveDiff_GTest, testValid_4) {

	vector<int> correctAns = { 151515151,151515159,151515951,151515959,151595151,151595159,151595951,151595959,159515151,159515159,159515951,159515959,159595151,159595159,159595951,159595959,262626262,373737373,404040404,404040484,404048404,404048484,404840404,404840484,404848404,404848484,484040404,484040484,484048404,484048484,484840404,484840484,484848404,484848484,515151515,515151595,515159515,515159595,515951515,515951595,515959515,515959595,595151515,595151595,595159515,595159595,595951515,595951595,595959515,595959595,626262626,737373737,840404040,840404048,840404840,840404848,840484040,840484048,840484840,840484848,848404040,848404048,848404840,848404848,848484040,848484048,848484840,848484848,951515151,951515159,951515951,951515959,951595151,951595159,951595951,951595959,959515151,959515159,959515951,959515959,959595151,959595159,959595951,959595959 };

	NumConsectiveDiff sut;
	auto res = sut.numsSameConsecDiff(9, 4);
	EXPECT_EQ(res.size(), correctAns.size());

	for (int i = 0; i < res.size(); i++) {
		EXPECT_EQ(res[i], correctAns[i]);
	}

}