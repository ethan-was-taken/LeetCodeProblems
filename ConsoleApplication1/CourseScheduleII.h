#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>

typedef pair<int, vector<int>> node;

class CourseScheduleII {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {

		setupGraph(numCourses, prerequisites);

		if (isGraphCyclic())
			return courseOrder;

		unordered_set<int> visitedMemo;
		for (node curr : graph)
			setCourseOrder(curr, visitedMemo);

		return courseOrder;

	};

private:
	unordered_map<int, vector<int>> graph;
	vector<int> courseOrder;

	void setupGraph(int numCourses, vector<vector<int>> &prerequisites) {

		for (int i = 0; i < prerequisites.size(); i++) {
			int curr = prerequisites[i][0];
			int neighbor = prerequisites[i][1];
			graph[curr].push_back(neighbor);
		}

		// fill in missing nodes
		for (int i = 0; i < numCourses; i++) {
			if (graph.find(i) == graph.end())
				graph.insert(node(i, vector<int>()));
		}

	};

	bool isGraphCyclic() {

		unordered_set<int> visitedMemo;
		for (node curr : graph) {

			if (visitedMemo.find(curr.first) != visitedMemo.end())
				continue;

			unordered_set<int> visitedOnPath;
			if (isPathCyclic(curr, visitedMemo, visitedOnPath))
				return true;

		}

		return false;

	};

	inline bool isPathCyclic(node currNode, unordered_set<int> &visitedMemo, unordered_set<int> &visitedOnPath) {

		if (visitedOnPath.find(currNode.first) != visitedOnPath.end())
			return true;

		// If we've already visited this node, we know that it's not cyclic
		if (visitedMemo.find(currNode.first) != visitedMemo.end())
			return false;

		visitedOnPath.emplace(currNode.first);
		visitedMemo.emplace(currNode.first);

		for (int currNeighbor : currNode.second) {

			node neighborNode = *graph.find(currNeighbor);
			if (isPathCyclic(neighborNode, visitedMemo, visitedOnPath))
				return true;

			visitedOnPath.erase(neighborNode.first);

		}

		return false;

	};

	// postorder
	void setCourseOrder(node currNode, unordered_set<int> &visitedMemo) {

		if (visitedMemo.find(currNode.first) != visitedMemo.end())
			return;
		// if we're at an unvisited leaf
		else if (currNode.second.empty() && visitedMemo.find(currNode.first) == visitedMemo.end()) {
			courseOrder.push_back(currNode.first);
			visitedMemo.emplace(currNode.first);
			return;
		}

		visitedMemo.emplace(currNode.first);

		for (int neighbor : currNode.second) {
			node neighborNode = *graph.find(neighbor);
			setCourseOrder(neighborNode, visitedMemo);
		}

		courseOrder.push_back(currNode.first);

	};


};