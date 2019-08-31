#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() { }

	/** Push element x onto stack. */
	void push(int x) {
		
		updateTopValue(x);

		if (storageOne.empty() && !storageTwo.empty())
			storageTwo.push(x);
		else
			storageOne.push(x);
			
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {

		int res;
		if (storageOne.empty())
			res = swapStorages(storageTwo, storageOne);
		else
			res = swapStorages(storageOne, storageTwo);

		return res;

	}

	/** Get the top element. */
	int top() {
		return topVal;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return storageOne.empty() && storageTwo.empty();
	}

private:
	queue<int> storageOne;
	queue<int> storageTwo;
	int topVal;


	inline int swapStorages(queue<int> &source, queue<int> &target) {

		int secondLastVal;
		while (source.size() > 1) {
			secondLastVal = source.front();
			target.push(source.front());
			source.pop();
		}

		updateTopValue(secondLastVal);

		int lastVal = source.front();
		source.pop();

		return lastVal;

	};

	inline void updateTopValue(int curr) {
		topVal = curr;
	};

};

/**
* Your MyStack object will be instantiated and called as such:
* MyStack obj = new MyStack();
* obj.push(x);
* int param_2 = obj.pop();
* int param_3 = obj.top();
* bool param_4 = obj.empty();
*/