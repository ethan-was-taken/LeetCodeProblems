#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// This code passed 32 / 37 test cases
class courseSchedule {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {

		if (prerequisites.empty() || prerequisites.size() == 1)
			return true;

		addToMap(prerequisites);

		unordered_multimap<int, int>::iterator it = prereq.begin();
		for (; it != prereq.end(); it++) {

			pair<int, int> curr(it->first, it->second);

			if (!dfs(curr))
				return false;

			currVisited.clear();
		}

		return true;
	};

private:
	inline bool dfs(pair<int, int> curr) {

		if (!currVisited.empty() && hasCycle(curr))
			return false;
		
		int numDups = prereq.count(curr.second);
		
		currVisited.insert(curr);
		if (totalVisited.find(curr.first) == totalVisited.end())
			totalVisited.insert(curr);

		if (numDups > 1) {

			for (int i = 0; i < numDups; i++) {

				pair<unordered_multimap<int, int>::iterator, unordered_multimap<int, int>::iterator> itPair = prereq.equal_range(curr.second);

				for (; itPair.first != itPair.second; itPair.first++) {
					
					unordered_multimap<int, int>::iterator curr2 = itPair.first;
					
					pair<int, int> travelTo(curr2->first, curr2->second);
					if (dfs(travelTo))
						return false;
				}
			}
		}
		
		unordered_multimap<int, int>::iterator temp = prereq.find(curr.second);

		if (temp == prereq.end())
			return true;
		
		if (!dfs(make_pair(temp->first, temp->second)))
			return false;
		
		return true;
	};

	bool hasCycle(pair<int, int> curr) {
		if (currVisited.find(curr.second) != currVisited.end())
			return true;
		return false;
	}

	void addToMap(vector<pair<int, int>>& prerequisites) {
		for (int i = 0; i < prerequisites.size(); i++) {
			pair<int, int> t = prerequisites[i];
			prereq.insert(t);
		}
	};

	unordered_multimap<int, int> prereq;
	unordered_multimap<int, int> currVisited;
	unordered_multimap<int, int> totalVisited;

};