#pragma once
#include <iostream>
#include <string>
#include <vector>


using namespace std;

struct customStack{
	customStack() : numParens(0), numBrackets(0), numSqBrackets(0) {};

	void push(char input) {

		cout << "pushing " << input << endl;

		if (input == '[')
			numSqBrackets++;
		else if (input == '{')
			numBrackets++;
		else if (input == '(')
			numParens++;

		stack.push_back(input);
	}

	bool popPlus(char input) {

		if (stack.empty()) {
			cout << "stack is empty and trying to pop: " << input << endl;
			return false;
		}

		char lastElement = stack.back();

		if (lastElement == '[' &&  input == ']') {
			numSqBrackets--;
			stack.pop_back();
		}
		else if (lastElement == '{' && input == '}') {
			numBrackets--;
			stack.pop_back();
		}
		else if (lastElement == '(' && input == ')') {
			numParens--;
			stack.pop_back();
		}
		else {
			cout << "last element didnt match input: " << lastElement  << ", " << input << endl;
			return false;
		}

		return true;
	}

	bool isValid() {
		return numBrackets == 0 && numParens == 0 && numSqBrackets == 0;
	}

private:
	int numParens;
	int numBrackets;
	int numSqBrackets;
	// in the real world a double linked list would be better
	vector<char> stack;
};

class validParentheses{
public:
	bool isValid(string s) {
		customStack *stack = new customStack();

		for (char ch : s) {
			if (shouldPop(ch)) {
				if(!stack->popPlus(ch))
					return false;
			}
			else
				stack->push(ch);
			
			cout << endl;
		}

		return stack->isValid();
	};

private:
	inline bool shouldPop(char input) {
		cout << "shouldPop: " << input << endl;
		if (input == ']')
			return true;
		else if (input == '}')
			return true;
		else if (input == ')')
			return true;
		cout << "shouldPop: returning false" << endl;
		return false;
	};
};