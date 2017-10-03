#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class combinations {
public:
	vector<vector<int>> combine(int n, int k) {
		/*
		1.	for(1 -> n-k+1)
				path.push_back(i)
				dfs(i + 1, k, path[])
				path.pop_back()

		2.	dfs(curr, k, path[]):
				if(path.size() == k)
					push_back(path)
					return;
				
				for(curr -> n-k+1)
					path.push_back(i)
					dfs(i + 1, k, path[])
					path.pop_back()
		*/

		dfs(1, n, k, vector<int>());

		return combos;

	};

private:
	inline void dfs(int curr, int n, int k, vector<int> &path) {

		if (path.size() == k) {
			cout << "adding previous path" << endl;
			combos.push_back(path);
			return;
		}

		for (int i = curr; i <= n; i++) {

			path.push_back(i);
			dfs(i + 1, n, k, path);

			print(path);

			path.pop_back();

		}

	};

	void print(vector<int> path) {

		cout << "path: " << endl;
		for (auto i : path) {
			cout << i << "\t";
		}
		cout << endl;

		int stop;
		cout << "\t\t\t\t\t\t";
		cin >> stop;

	}

	// Global Vars
	vector<vector<int>> combos;
};