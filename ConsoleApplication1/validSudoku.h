#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// A relatively generalized sudoku checker
class validSudoku {
public:
	bool isValidSudoku(vector<vector<char>>& board) {

		if (board.empty())
			return false;

		// Check rows
		bool rowCheck = generalizedCheck(board, 0, board.size(), 0, board[0].size(), false);
		if (!rowCheck)
			return false;

		// Check columns
		bool colCheck = generalizedCheck(board, 0, board[0].size(), 0, board.size(), true);
		if (!colCheck)
			return false;
	
		// Check inner square
		bool subSquareCheck = checkSubSquares(board);

		return subSquareCheck;

	};

	inline bool generalizedCheck(vector<vector<char>>& board, int rowStart, int rowEnd, int colStart, int colEnd, bool checkCol) {

		for (int i = rowStart; i < rowEnd; i++) {

			unordered_set<char> currValues;

			for (int j = colStart; j < colEnd; j++) {

				int tempI = i;
				int tempJ = j;

				if (checkCol) {
					tempI = j;
					tempJ = i;
				}
				
				if (board[tempI][tempJ] == '.')
					continue;

				if (currValues.find(board[tempI][tempJ]) != currValues.end())
					return false;

				currValues.insert(board[tempI][tempJ]);

			}

		}

		return true;

	};

private:
	inline bool squareCheck(vector<vector<char>>& board, int rowStart, int rowEnd, int colStart, int colEnd) {
		
		unordered_set<char> currValues;

		for (int i = rowStart; i < rowEnd; i++) {

			for (int j = colStart; j < colEnd; j++) {

				int tempI = i;
				int tempJ = j;

				if (board[tempI][tempJ] == '.')
					continue;

				if (currValues.find(board[tempI][tempJ]) != currValues.end())
					return false;

				currValues.insert(board[tempI][tempJ]);

			}

		}

		return true;
	};

	inline bool checkSubSquares(vector<vector<char>>& board) {
				
		for (int i = 0; i < board.size(); i += 3) {

			int subSquareSize1 = board.size() / 3 + i;

			for (int j = 0; j < board.size(); j += 3) {

				int subSquareSize2 = board.size() / 3 + j;
				bool colCheck = squareCheck(board, i, subSquareSize1, j, subSquareSize2);
				if (!colCheck)
					return false;

			}

		}

		return true;

	};

};