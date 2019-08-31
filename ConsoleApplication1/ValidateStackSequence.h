#pragma once
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class ValidateStackSequence {
public:
	/*
	Algo: 
		(1) Push vals from pushed until stack.top() == popped.first()
		(2) while stack.top() == popped.first() stack.pop()
		(3) if pushed.empty() and popped.first() != stack.top() return false
		(4) else continue popping stack.top() until popped.empty() OR popped.first() != stack.top()
	*/
	bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
		
		setup(pushed, popped);

		while (!isStackValidated()) {

			for (; isInBounds() && getStackTop() != popped[poppedIndex]; pushedIndex++)
				stack_.push(pushed[pushedIndex]);

			if (isInvalidPushPopSequence())
				return false;

			for (; isInBounds(poppedIndex) && getStackTop() == popped[poppedIndex]; poppedIndex++)
				stack_.pop();

		 }

		return true;

	};

private:
	stack<int> stack_;
	vector<int>* pushed;
	vector<int>* popped;
	int pushedIndex;
	int poppedIndex;

	void setup(vector<int> &_pushed, vector<int> &_popped) {
		pushedIndex = 0;
		poppedIndex = 0;
		pushed = &_pushed;
		popped = &_popped;
	};

	bool isStackValidated() {
		return !isInBounds(pushedIndex) && !isInBounds(poppedIndex) && stack_.empty();
	};

	bool isInBounds(int index) {
		return index < pushed->size();
	};

	bool isInBounds() {
		return isInBounds(pushedIndex) && isInBounds(poppedIndex);
	};

	int getStackTop() {
		return stack_.empty() ? INT_MIN : stack_.top();
	};

	bool isInvalidPushPopSequence() {
		return !isInBounds(pushedIndex) && getStackTop() != popped->at(poppedIndex);
	};

};