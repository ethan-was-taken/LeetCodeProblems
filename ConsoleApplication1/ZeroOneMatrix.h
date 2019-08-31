#pragma once
#include <vector>
#include <iostream>
#include <queue>

#define QUEUE queue<PositionInfo> 

using namespace std;

struct PositionInfo {
	int row;
	int col;
	int data;
	PositionInfo(int row, int col, int data) {
		this->row = row;
		this->col = col;
		this->data = data;
	};
};

class ZeroOneMatrix {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {

		setup(matrix);

		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix.size(); j++)
				breadthFirstSearch(i, j);
		}

		return res;

	};

private:
	vector<vector<int>> matrix;
	vector<vector<bool>> visited;
	vector<vector<int>> res;

	void setup(vector<vector<int>> &matrix) {
		this->matrix = matrix;
		res.resize(matrix.size(), vector<int>(matrix[0].size(), 0));
	};

	void breadthFirstSearch(int row, int col) {

		visited.clear();
		visited.resize(matrix.size(), vector<bool>(matrix[0].size(), false));
		visited[row][col] = true;
		
		QUEUE queue;
		queue.push(PositionInfo(row, col, matrix[row][col]));

		while (!queue.empty()) {

			auto curr = queue.front();
			queue.pop();

			if (curr.data == 0) {
				res[row][col] = abs(row - curr.row) + abs(col - curr.col);
				return;
			}

			addToQueue(queue, curr.row, curr.col + 1);
			addToQueue(queue, curr.row + 1, curr.col);
			addToQueue(queue, curr.row, curr.col - 1);
			addToQueue(queue, curr.row - 1, curr.col);

		}		

	};

	inline void addToQueue(QUEUE &queue, int row, int col) {
		if (!isValidPosition(row, col))
			return;
		visited[row][col] = true;
		queue.push(PositionInfo(row, col, matrix[row][col]));
	};

	inline bool isValidPosition(int row, int col) {
		return row >= 0 && col >= 0 && row < matrix.size() && col < matrix.size() && !visited[row][col];
	};

};