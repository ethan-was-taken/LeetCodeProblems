#pragma once
#include <string>
#include <algorithm>

using namespace std;

class reverseCharString {
public:
	static void reverse(char* str) {

		char* end = str;
		while (*end++);
		end--;

		for (; str < end; str++, end--) {
			char temp = *str;
			*str = *end;
			*end = temp;
		}
				
	};

};