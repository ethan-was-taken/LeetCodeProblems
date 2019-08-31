#include "pch.h"
#include "..\ConsoleApplication1\validPalindrome.h"

int main(int argc, char **argv) {

	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
/*
TEST(ValidPalindromeTest, emptyInput) {
	ValidPalindrome sut;
	auto res = sut.isPalindrome("");
	EXPECT_TRUE(res);
}

TEST(ValidPalindromeTest, spaces) {
	ValidPalindrome sut;
	auto res = sut.isPalindrome(" ");
	EXPECT_TRUE(res);
}

TEST(ValidPalindromeTest, sizeOneInput) {
	ValidPalindrome sut;
	auto res = sut.isPalindrome("a");
	EXPECT_TRUE(res);
}

TEST(ValidPalindromeTest, validNumbersInput) {
	ValidPalindrome sut;
	auto res = sut.isPalindrome("11");
	EXPECT_TRUE(res);
}

TEST(ValidPalindromeTest, invalidNumbersInput) {
	ValidPalindrome sut;
	auto res = sut.isPalindrome("12");
	EXPECT_FALSE(res);
}
*/