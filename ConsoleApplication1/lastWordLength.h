#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <unordered_map>

#include "printer.h"


using namespace std;


class lastWordLength {
public:
	static int lengthOfLastWord(string s) {

		int startPos = s.find_last_of(' ');
		if (startPos == string::npos)
			return s.size();
	
		string subAfter = s.substr(startPos + 1);		
		if (subAfter.size() == 0)
			return lengthOfLastWord(s.substr(0, startPos));
						
		return subAfter.size();	

	};

};