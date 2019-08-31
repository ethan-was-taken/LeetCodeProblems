#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <stack>

#include "printer.h"
#include "stopper.h"

#define BASE 26

using namespace std;

class excelSheetColumnTitle {
public:
	string convertToTitle(int n) {

		
	};

private:
	inline stack<char> getColumnTitle(int n) {
		
	};

	const unordered_map<int, char> mapper = {
		pair<int, char>(0,'Z'),
		pair<int, char>(1,'A'),
		pair<int, char>(2,'B'),
		pair<int, char>(3,'C'),
		pair<int, char>(4,'D'),
		pair<int, char>(5,'E'),
		pair<int, char>(6,'F'),
		pair<int, char>(7,'G'),
		pair<int, char>(8,'H'),
		pair<int, char>(9,'I'),
		pair<int, char>(10,'J'),
		pair<int, char>(11,'K'),
		pair<int, char>(12,'L'),
		pair<int, char>(13,'M'),
		pair<int, char>(14,'N'),
		pair<int, char>(15,'O'),
		pair<int, char>(16,'P'),
		pair<int, char>(17,'Q'),
		pair<int, char>(18,'R'),
		pair<int, char>(19,'S'),
		pair<int, char>(20,'T'),
		pair<int, char>(21,'U'),
		pair<int, char>(22,'V'),
		pair<int, char>(23,'W'),
		pair<int, char>(24,'X'),
		pair<int, char>(25,'Y')
	};

};