#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class gameLife {
public:
	void gameOfLife(vector<vector<int>>& board) {

		vector<pair<int, int>> statesToChange;

		for (int row = 0; row < board.size(); row++) {

			for (int col = 0; col < board[row].size(); col++) {

				int numLiveNeighbors = checkHorizontal(board, row, col);
				numLiveNeighbors += checkVertical(board, row, col);
				numLiveNeighbors += checkDiagonal(board, row, col);

				bool isAlive = board[row][col] == 1;
				bool diedUnderPop = numLiveNeighbors < 2;
				bool diedOverPop = numLiveNeighbors > 3;
				bool born = numLiveNeighbors == 3;

				if (isAlive && (diedUnderPop || diedOverPop)) 
					statesToChange.push_back(pair<int, int>(row, col));
				else if (!isAlive && born) 
					statesToChange.push_back(pair<int, int>(row, col));

			}

		}

		for (int i = 0; i < statesToChange.size(); i++) {

			pair<int, int> curr = statesToChange[i];

			if (board[curr.first][curr.second] == 0)
				board[curr.first][curr.second] = 1;
			else if (board[curr.first][curr.second] == 1)
				board[curr.first][curr.second] = 0;

		}

	};

private:
	inline int checkHorizontal(vector<vector<int>>& board, int row, int col) {

		int upperBound = board[row].size();

		bool colUpperBound = col + 1 < upperBound;
		bool colLowerBound = col - 1 >= 0;

		int numLiveNeighbors = 0;
		if (colUpperBound && board[row][col + 1] == 1)
			numLiveNeighbors++;
		if (colLowerBound && board[row][col - 1] == 1)
			numLiveNeighbors++;

		return numLiveNeighbors;

	};

	inline int checkVertical(vector<vector<int>>& board, int row, int col) {

		int upperBound = board.size();

		bool rowUpperBound = row + 1 < upperBound;
		bool rowLowerBound = row - 1 >= 0;

		int numLiveNeighbors = 0;
		if (rowUpperBound && board[row + 1][col] == 1)
			numLiveNeighbors++;
		if (rowLowerBound && board[row - 1][col] == 1)
			numLiveNeighbors++;

		return numLiveNeighbors;

	};

	inline int checkDiagonal(vector<vector<int>>& board, int row, int col) {

		int colUB = board[row].size();
		int rowUB = board.size();

		bool colUpperBound = col + 1 < colUB;
		bool rowUpperBound = row + 1 < rowUB;
		bool colLowerBound = col - 1 >= 0;
		bool rowLowerBound = row - 1 >= 0;

		int numLiveNeighbors = 0;
		if (rowLowerBound && colLowerBound && board[row - 1][col - 1] == 1)
			numLiveNeighbors++;
		if (rowUpperBound && colLowerBound && board[row + 1][col - 1] == 1)
			numLiveNeighbors++;
		if (rowLowerBound && colUpperBound && board[row - 1][col + 1] == 1)
			numLiveNeighbors++;
		if (rowUpperBound && colUpperBound && board[row + 1][col + 1] == 1)
			numLiveNeighbors++;

		return numLiveNeighbors;

	};

};