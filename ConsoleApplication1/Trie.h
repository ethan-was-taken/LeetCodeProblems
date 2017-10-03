#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct TrieNode {

	// Does this node represent a complete word?
	bool isWord;
	// The current text of the node
	char text;
	vector<TrieNode*> children;

	TrieNode() {
		this->isWord = false;
		this->text = ' ';
	};
	TrieNode(bool isWord) {
		this->isWord = isWord;
		this->text = ' ';
	};
	TrieNode(char text) {
		this->isWord = false;
		this->text = text;
	};
	TrieNode(bool isWord, char text) {
		this->isWord = isWord;
		this->text = text;
	};

	TrieNode* getReleventNode(char word) {
		
		if (children.size() == 0)
			return nullptr;
		
		for (auto child : children) {
			if (child->text == word)
				return child;
			
		}
	
		return this;
	};

};

class Trie {
public:
	/** Initialize your data structure here. */
	Trie() {
		head = new TrieNode();
	};

	/** Inserts a word into the trie. */
	void insert(string word) {

		TrieNode *ptr = head;

		for (int i = 0; i < word.size(); i++) {

			TrieNode *child = ptr->getReleventNode(word[i]);

			if (child != nullptr && word[i] == child->text) {

				if (i + 1 == word.size()) {
					child->isWord = true;
					return;
				}

				ptr = child;
				continue;
			}

			bool isWord = (i + 1 >= word.size() ? true : false);
			char text = word[i];

			TrieNode *toAdd = new TrieNode(isWord, text);
			ptr->children.push_back(toAdd);
			ptr = toAdd;

		}

	};

	/** Returns true if the word is in the trie. */
	bool search(string word) {

		cout << word << endl;

		TrieNode *ptr = head;

		for (char ch : word) {

			ptr = ptr->getReleventNode(ch);
			if (ptr == nullptr)
				return false;

		}
		
		return ptr->isWord && word[word.size() - 1] == ptr->text;
	};

	/** Returns true if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		
		TrieNode *ptr = head;

		for (char ch : prefix) {

			ptr = ptr->getReleventNode(ch);
			if (ptr == nullptr)
				return false;

		}

		return ptr->isWord && prefix[prefix.size() - 1] == ptr->text;
	};

private:
	//------Global Vars------
	TrieNode *head;

};
