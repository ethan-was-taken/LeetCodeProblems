#pragma once
#include <vector>
#include <algorithm>
#include <unordered_set>

#define LOWERBOUND 1
#define UPPERBOUND 9

using namespace std;

struct PathInfo {
	vector<int> path;
	unordered_set<unsigned short> visitedOnPath;
	
	int curr;
	unsigned short pathSum;

	PathInfo(int init) {
		this->init = init;
		curr = init;
		pathSum = init;
	};

	void increasePathInfoBy(int value) {
		curr = value;
		visitedOnPath.emplace(value);
		path.push_back(value);
		pathSum += value;
	};

	void decreasePathInfoBy(int value) {
		visitedOnPath.erase(visitedOnPath.find(value));
		path.pop_back();
		pathSum -= value; 
		curr = !path.empty() ? path.back() : init;
	};

	bool contains(int value) {
		return visitedOnPath.find(value) != visitedOnPath.end();
	};

	int size() {
		return path.size();
	};

private:
	int init;

};

class ComboSumIII {
public:
	vector<vector<int>> combinationSum3(int vecSize, int target) {

		targetVecSize = vecSize;
		targetSum = target;

		PathInfo path(LOWERBOUND - 1);
		dfs(path);

		return result;

	};

private:
	vector<vector<int>> result;
	int targetVecSize;
	int targetSum;

	void dfs(PathInfo &path) {

		int nextOnPath = targetSum - path.pathSum;
		if (isInvalidStoppingPoint(path, nextOnPath))
			return;
		else if (path.size() == targetVecSize - 1 && !path.contains(nextOnPath)) {

			path.path.push_back(nextOnPath);
			result.push_back(path.path);
			path.path.pop_back();

			return;

		}
		
		for (int i = path.curr + 1; i <= UPPERBOUND; i++) {

			if (path.contains(i))
				continue;
			else if ((path.pathSum + i) > targetSum)
				break;

			path.increasePathInfoBy(i);
			dfs(path);
			path.decreasePathInfoBy(i);

		}

	};

	inline bool isInvalidStoppingPoint(PathInfo &path, int nextOnPath) {

		bool isVecSizeLargerThanTarget = path.size() >= targetVecSize;
		bool isSumLargerThanTarget = path.pathSum >= targetSum;
		bool isInvalidNextValue = nextOnPath <= path.curr;
		bool isOverUpperBound = nextOnPath > UPPERBOUND && path.size() == targetVecSize - 1;
		bool hasDuplicateOnPath = path.size() == targetVecSize - 1 && path.contains(nextOnPath);

		return isVecSizeLargerThanTarget || isSumLargerThanTarget || isInvalidNextValue || isOverUpperBound || hasDuplicateOnPath;

	};

};