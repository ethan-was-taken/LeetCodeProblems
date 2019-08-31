#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <algorithm>

#include "printer.h"

using namespace std;

template<class T>
class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() { };

	/** Push element x to the back of queue. */
	void push(T x) {

		if (storage.empty()) {
			storage.push(x);
			return;
		}

		stack<T> temp;
		while (!storage.empty())
			temp.push(this->pop());
		
		temp.push(x);

		while (!temp.empty()) {
			storage.push(temp.top());
			temp.pop();
		}
			
	};

	/** Removes the element from in front of queue and returns that element. */
	T pop() {
		T toReturn = storage.top();
		storage.pop();
		return toReturn;
	};

	/** Get the front element. */
	T peek() {
		return storage.top();
	};

	/** Returns whether the queue is empty. */
	bool empty() {
		return storage.empty();
	};

private:
	stack<T> storage;
};

/**
* Your MyQueue object will be instantiated and called as such:
* MyQueue obj = new MyQueue();
* obj.push(x);
* int param_2 = obj.pop();
* int param_3 = obj.peek();
* bool param_4 = obj.empty();
*/