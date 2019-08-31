#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define ITERATOR multiset<VectorNode, VectorNodeComp>::iterator 

using namespace std;

struct VectorNode {

	int sourceNode;
	int destinationNode;
	int cost;

	VectorNode(vector<int> &vec) {

		if (vec.size() != 3)
			throw runtime_error("VectorNode only takes vectors with size of 3");

		sourceNode = vec[0];
		destinationNode = vec[1];
		cost = vec[2];

	};

	inline friend bool operator<(const int &leftHandSide, const VectorNode &rightHandSide) {
		return leftHandSide < rightHandSide.sourceNode;
	};

	inline friend bool operator<(const VectorNode &leftHandSide, const int &rightHandSide) {
		return leftHandSide.sourceNode < rightHandSide;
	};

};

struct VectorNodeComp {
	
	inline bool operator()(const VectorNode &vec1, const VectorNode &vec2) const {

		if (vec1.sourceNode == vec2.sourceNode && vec1.destinationNode == vec2.destinationNode)
			return vec1.cost < vec2.cost;
		else if (vec1.sourceNode == vec2.sourceNode)
			return vec1.destinationNode < vec2.destinationNode;

		return vec1.sourceNode < vec2.sourceNode;

	};

	inline friend bool operator==(const VectorNode &vec1, const VectorNode &vec2) {
		return vec1.sourceNode == vec2.sourceNode && vec1.destinationNode == vec2.destinationNode && vec1.cost == vec2.cost;
	};

};

class NetworkDelayTime {
public:
	int networkDelayTime(vector<vector<int>> &times_, int numNodes, int startNode) {

		setup(times_, startNode);
		findLongestDelayTime(startNode, 0);

		return 	totalVisited.size() == times_.size() ? longestDelayTime : -1;

	};

private:
	multiset<VectorNode, VectorNodeComp> times;
	multiset<VectorNode, VectorNodeComp> totalVisited;
	set<VectorNode, VectorNodeComp> currPathVisited;
	int startNode;
	unsigned int longestDelayTime;

	void setup(vector<vector<int>> &times_, int startNode) {
		this->startNode = startNode;
		longestDelayTime = 0;
		for (auto curr : times_)
			times.emplace(VectorNode(curr));
	};

	void findLongestDelayTime(int startNode, unsigned int currPathDelayTime) {

		auto range = std::equal_range(times.begin(), times.end(), startNode);
		addToTotalVisited(range);
		if (hasReachedEnd(range, startNode)) {
			currPathDelayTime += range.second == times.end() ? range.first->cost : 0;
			longestDelayTime = max(currPathDelayTime, longestDelayTime);
			return;
		}

		for (ITERATOR curr = range.first; curr != range.second; curr++) {

			if (hasVisited(*curr))
				continue;

			int currDelayTime = curr->cost;
			currPathVisited.emplace(*curr);

			findLongestDelayTime(curr->destinationNode, currPathDelayTime + currDelayTime);

			currPathVisited.erase(*curr);

		}

		currPathVisited.clear();


	};

	inline bool hasReachedEnd(const pair<ITERATOR, ITERATOR> &range, const int &startNode) {
		return  range.second == times.end() ||
			(range.first == range.second && range.first->sourceNode != startNode);
	}

	inline bool hasVisited(VectorNode node) {
		return currPathVisited.find(node) != currPathVisited.end();
	};

	inline void addToTotalVisited(pair<ITERATOR, ITERATOR> &node) {
		for (auto curr = node.first; curr != node.second; curr++) {
			if (totalVisited.find(*curr) == totalVisited.end())
				totalVisited.emplace(*curr);
		}
	};

};