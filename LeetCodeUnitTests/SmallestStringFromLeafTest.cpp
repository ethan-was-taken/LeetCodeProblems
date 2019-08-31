#include "pch.h"
#include "..\ConsoleApplication1\SmallestStringFromLeaf.h"
#include <Random>

TEST(SmallestStringFromLeafTest, testEmptyTree) {

	TreeNode* root = nullptr;

	SmallestStringFromLeaf in;
	auto res = in.smallestFromLeaf(root);

	EXPECT_EQ(res, "");

}

TEST(SmallestStringFromLeafTest, testSingleNodeTree) {

	TreeNode* root = new TreeNode(0);

	SmallestStringFromLeaf in;
	auto res = in.smallestFromLeaf(root);

	EXPECT_EQ(res, "a");

}

TEST(SmallestStringFromLeafTest, testPerfectTree) {

	TreeNode* root = new TreeNode(0);
	
	TreeNode* ptr = root;
	ptr->left = new TreeNode(1);
	ptr->right = new TreeNode(2);

	ptr = ptr->left;
	ptr->left = new TreeNode(3);
	ptr->right = new TreeNode(4);

	ptr = root->right;
	ptr->left = new TreeNode(3);
	ptr->right = new TreeNode(4);

	SmallestStringFromLeaf in;
	auto res = in.smallestFromLeaf(root);

	EXPECT_EQ(res, "dba");

}

// Test to ensure that the shorter string "zz" is returned and not a "smaller" string like "zaa"
TEST(SmallestStringFromLeafTest, testLongerStrButLexigraphicallySmaller) {

	TreeNode* root = new TreeNode(25);

	TreeNode* ptr = root;
	ptr->left = new TreeNode(0);
	ptr->right = new TreeNode(25);

	ptr = ptr->left;
	ptr->left = new TreeNode(1);
	ptr->right = new TreeNode(2);

	SmallestStringFromLeaf in;
	auto res = in.smallestFromLeaf(root);

	EXPECT_EQ(res, "baz");

}


TEST(SmallestStringFromLeafTest, testCompleteTree_LexigraphicallySmallerWins) {

	TreeNode* root = new TreeNode(25);

	TreeNode* ptr = root;
	ptr->left = new TreeNode(1);
	ptr->right = new TreeNode(3);

	ptr = ptr->left;
	ptr->left = new TreeNode(1);
	ptr->right = new TreeNode(3);

	ptr = root->right;
	ptr->left = new TreeNode(0);
	ptr->right = new TreeNode(2);

	SmallestStringFromLeaf in;
	auto res = in.smallestFromLeaf(root);

	EXPECT_EQ(res, "adz");

}

TEST(SmallestStringFromLeafTest, test_LC_48) {

#define ASCII_A 97

	cout << (char)(3 + ASCII_A) << endl;
	cout << (char)(9 + ASCII_A) << endl;
	cout << (char)(20 + ASCII_A) << endl;
	cout << (char)(15 + ASCII_A) << endl;
	cout << (char)(7 + ASCII_A) << endl;

	TreeNode* root = new TreeNode(3);

	TreeNode* ptr = root;
	ptr->left = new TreeNode(9);
	ptr->right = new TreeNode(20);

	ptr = root->right;
	ptr->left = new TreeNode(15);
	ptr->right = new TreeNode(7);

	SmallestStringFromLeaf in;
	auto res = in.smallestFromLeaf(root);

	EXPECT_EQ(res, "hud");

}