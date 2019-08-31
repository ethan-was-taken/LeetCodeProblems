#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>

#define EQUALITY_POS 1
#define RHS_BEG_POS 3

using namespace std;

struct GraphNode {
	string key;
	unordered_map<string, GraphNode*> neighbors;
	GraphNode(string key_) : key(key_) {};
};

class EqualityEquations {
public:
	/*
	test: c != c
	*/
	bool equationsPossible(vector<string> &equations) {

		updateNotEqualEquations(equations);
		setGraph(equations);

		print();

		return false;

	};

	void print() {

		for (pair<string, GraphNode*> curr : graph) {
			
			cout << "current:\t" << curr.second->key << endl;
			
			cout << "neighbors:\t";
			for (pair<string, GraphNode*> neighbors : curr.second->neighbors)
				cout << neighbors.first << " ";
			cout << endl;

		}

	};

private:
	unordered_map<string, GraphNode*> graph;

	// Takes equations of the form a != b and changes it to a==!b
	void updateNotEqualEquations(vector<string> &equations) {

		for (int i = 0; i < equations.size(); i++) {

			string* curr = &equations[i];

			if (curr->at(EQUALITY_POS) == '!') {
				curr->replace(EQUALITY_POS, 1,"=");
				curr->insert(curr->begin() + RHS_BEG_POS, '!');
			}

		}

	};

	void setGraph(vector<string> &equations) {

		for (string curr : equations) {

			GraphNode* currNode = getNode(curr.substr(0,1));
			GraphNode* neighnorNode = getNode(curr.substr(RHS_BEG_POS));

			if (currNode->key == neighnorNode->key)
				continue;

			currNode->neighbors.insert(pair<string, GraphNode*>(neighnorNode->key, neighnorNode));

		}

	};

	inline GraphNode* getNode(string input) {
		
		if (graph.find(input) != graph.end())
			return graph.find(input)->second;
		
		GraphNode* res = new GraphNode(input);
		graph.insert(pair<string, GraphNode*>(input, res));

		return res;

	};

};