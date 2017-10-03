#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>


using namespace std;

class wordLadder {
public:
	/*
	0.	if word list doesnt have endword in it, add it
	1.	replace letter i in begin word with a-z and get the list of neighbors
	2.	for each level of neighbors increase a counter
	3.	repeat for each neighbors -> BFS
	4.	when a list of neighbors has the endword then you've reached the end
	*/
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

		cout << "list:\t\t";
		for (string curr : wordList) {
			cout << curr << setw(10);
		}
		cout << endl;

		if (beginWord.size() == 1)
			return wordList.size() - 1;

		add(wordList);

		if (words.find(endWord) == words.end())
			return 0;

		foundEnd = false;

		queue<string> neighbors;
		neighbors.push(beginWord);
		
		int count = 0;

		while (!neighbors.empty()) {

			count++;

			string curr = neighbors.front();
			neighbors.pop();

			getNeighbors(curr, neighbors, endWord);

			if (foundEnd)
				break;


			print(wordList, neighbors);

		}

		cout << "count:\t" << count << endl;

		if (words.find(beginWord) != words.end())
			count++;

		return foundEnd ? count : 0;

	};

	int ladderLength2(string beginWord, string endWord, vector<string>& wordList) {

		add(wordList);

		foundEnd = false;

		queue<string> neighbors;
		getNeighbors(beginWord, neighbors, endWord);

		int count = 2;

		while (!neighbors.empty()) {

			int size = neighbors.size();

			for (int i = 0; i < size; i++) {

				string curr = neighbors.front();
				neighbors.pop();

				if (curr == endWord)
					return count;

				getNeighbors(curr, neighbors, endWord);

			}

			count++;

		}

		return 0;

	};

private:
	inline void add(vector<string>& wordList) {
		for (string curr : wordList)
			words.insert(curr);	
	};


	inline void getNeighbors(string curr, queue<string> &neighbors, string end) {

		for (int i = 0; i < curr.size(); i++) {

			for (int j = 0; j < 27; j++) {

				string temp = curr;
				temp[i] = 'a' + j;

				if (temp != curr && words.find(temp) != words.end() && visited.find(temp) == visited.end()) {
					neighbors.push(temp);
					visited.insert(temp);

					if (temp == end) {
						cout << "FOUND END!!!" << endl;
						foundEnd = true;
					}

				}

			}

		}

	}

	void print(vector<string>& wordList, queue<string> neighbors) {

		int width = 10;

		cout << "neighbors:\t";
		while (!neighbors.empty()) {

			string curr = neighbors.front();
			neighbors.pop();

			cout << curr << setw(width);

		}
		cout << endl;
		
		cout << "visited:\t";
		unordered_set<string>::iterator it = visited.begin();
		for (; it != visited.end(); it++) {
			cout << *(it) << setw(width);
		}
		cout << endl;

		stopper();


	};

	void stopper() {

		int stop;
		cout << "\t\t\t\t\t";
		cin >> stop;

	};

	// Global Vars
	unordered_set<string> words;
	unordered_set<string> visited;
	bool foundEnd;


};