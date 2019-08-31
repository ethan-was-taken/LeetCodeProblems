#pragma once
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class FriendCircles {
public:
	int findCircleNum(vector<vector<int>> &m) {
		
		setup(m);

		int numFriendCircles = 0;

		for (int i = 0; i < m.size(); i++) {

			if (visitedFriend[i])
				continue;

			visitedFriend[i] = true;
			traverseFriendCircle(i);
			numFriendCircles++;

		}

		return numFriendCircles;

	};

private:
	vector<vector<int>> friendMatrix;
	vector<bool> visitedFriend;

	void setup(vector<vector<int>> &m) {
		friendMatrix = m;
		visitedFriend.resize(m.size());
	};
	
	void traverseFriendCircle(int index) {

		for (int i = 0; i < friendMatrix.size(); i++) {

			if (friendMatrix[index][i] == 0 || visitedFriend[i])
				continue;

			visitedFriend[i] = true;
			traverseFriendCircle(i);

		}

	};

};