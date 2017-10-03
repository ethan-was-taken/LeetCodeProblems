#pragma once
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class listWithRandomPointer {
public:
	RandomListNode* copyRandomList(RandomListNode* head) {

		RandomListNode* ptr = head;
		RandomListNode* list = new RandomListNode(ptr->label);
		if(ptr->random != NULL)
			list->random = new RandomListNode(ptr->random->label);

		RandomListNode* listHead = list;

		ptr = ptr->next;
		cout << ptr->label << endl;
		cout << ptr->random->label << endl;

		print(listHead);


		while (ptr != NULL) {

			list->next = new RandomListNode(ptr->label);
			if (ptr->random != NULL)
				list->next->random = new RandomListNode(ptr->random->label);
			else
				cout << "ptrRandom == NULL" << endl;

			ptr = ptr->next;
			list = list->next;

			print(listHead);

		}

		return listHead;

	};

private:
	inline RandomListNode* getDeepList(RandomListNode* curr, RandomListNode* list, RandomListNode* head) {

		

	};

	void print(RandomListNode* curr) {

		cout << "list:\t\t";
		while (curr != NULL) {

			if(curr->random != NULL)
				cout << "{"<< curr->label << ", " << curr->random->label << "}\t";
			else 
				cout << "{" << curr->label << ", " << "#" << "}\t";

			curr = curr->next;

		}
		cout << endl;

		//print();

		int stop;
		cout << "\t\t\t\t\t";
		cin >> stop;

	};

	void print() {
		cout << "visited:\t";
		for (auto curr : visitedNodes) {

			cout << curr->label << "\t";
			curr = curr->next;

		}
		cout << endl;
	};

	// global vars
	unordered_set<RandomListNode*> visitedNodes;

};