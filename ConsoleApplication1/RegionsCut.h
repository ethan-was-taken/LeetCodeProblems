#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class RegionsCut {
public:
	int regionsBySlashes(vector<string> &grid) {
		
		setup(grid);

		for (int row = 0; row < visited.size(); row++) {
			for (int col = 0; col < visited[row].size(); col++) {
				if (visited[row][col] != ' ') 
					continue;
				bfs(row, col);
			}
		}

		for (string curr : visited) {
			cout << curr << endl;
		}

		return regionNum;

	};

private:
	vector<string> visited;
	int regionNum;
	
	void setup(vector<string> &grid) {

		vector<string> temp(grid.size() * 3, string(' ', grid[0].size() * 3));


		visited = grid;
		regionNum = 0;		
	};

	void bfs(int startRow, int startCol) {

		regionNum++;

		queue<pair<int, int>> que;
		que.push(make_pair(startRow, startCol));

		while (!que.empty()) {

			pair<int, int> currPos = que.front();
			que.pop();

			int row = currPos.first;
			int col = currPos.second;

			visited[row][col] = (char)regionNum;

			addToQueueForBFS(que, row, col);

		}

	};

	void addToQueueForBFS(queue<pair<int, int>> &que, int row, int col) {
		// right
		if (col + 1 < visited[row].size() && visited[row][col + 1] == ' ')
			que.push(make_pair(row, col + 1));
		// down
		if (row + 1 < visited.size() && visited[row + 1][col] == ' ')
			que.push(make_pair(row + 1, col));
		// Left
		if (col - 1 >= 0 && visited[row][col - 1] == ' ')
			que.push(make_pair(row, col - 1));
		// up
		if (row - 1 >= 0 && visited[row - 1][col] == ' ')
			que.push(make_pair(row - 1, col));
	};

};