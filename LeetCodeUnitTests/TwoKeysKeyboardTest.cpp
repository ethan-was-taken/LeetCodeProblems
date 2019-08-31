#include "pch.h"
#include "..\ConsoleApplication1\TwoKeysKeboard.h"
#include <Random>

TEST(TwoKeysKeboardTest, oddInput) {

	TwoKeysKeboard sut;
	auto res = sut.minSteps(15);

	EXPECT_EQ(res, 8);

}

TEST(TwoKeysKeboardTest, primeInput) {

	TwoKeysKeboard sut;
	
	auto res = sut.minSteps(3);
	EXPECT_EQ(res, 3);

	res = sut.minSteps(5);
	EXPECT_EQ(res, 5);

	res = sut.minSteps(7);
	EXPECT_EQ(res, 7);

	res = sut.minSteps(11);
	EXPECT_EQ(res, 11);

	res = sut.minSteps(13);
	EXPECT_EQ(res, 13);
	
}

TEST(TwoKeysKeboardTest, evenInput) {

	TwoKeysKeboard sut;

	auto res = sut.minSteps(4);
	EXPECT_EQ(res, 4);

	res = sut.minSteps(6);
	EXPECT_EQ(res, 5);

	res = sut.minSteps(12);
	EXPECT_EQ(res, 7);

	res = sut.minSteps(14);
	EXPECT_EQ(res, 9);

	res = sut.minSteps(24);
	EXPECT_EQ(res, 9);

}

TEST(TwoKeysKeboardTest, maxInput) {

	TwoKeysKeboard sut;

	auto res = sut.minSteps(1000);
	EXPECT_EQ(res, 21);

}

TEST(TwoKeysKeboardTest, invalidInput) {

	TwoKeysKeboard sut;

	auto res = sut.minSteps(1);
	EXPECT_EQ(res, 1);

	res = sut.minSteps(2);
	EXPECT_EQ(res, 2);

	res = sut.minSteps(3);
	EXPECT_EQ(res, 3);

	res = sut.minSteps(4);
	EXPECT_EQ(res, 4);

}