#include <iostream>
#include <string>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//double is larger than long long, try taht instead
class addTwoNums {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

			long long num1 = linkedListToInt(l1);
			long long num2 = linkedListToInt(l2);

			cout << "num1: " << num1 << endl;
			cout << "num2: " << num2 << endl;

			long long sum = num1 + num2;

			cout << "sum: " << sum << endl;

			return intToLinkedList(sum);

		};

		ListNode* intToLinkedList(long long input) {

			cout << "input: " << input << endl;

			const int SIZE = (int)to_string(input).size();
			long curr = input % 10;
			input /= 10;
			ListNode *toReturn = new ListNode(curr);

			if (SIZE == 1)
				return toReturn;
	
			ListNode *originNext = new ListNode(-1);
			toReturn->next = originNext;

			ListNode *ptr = originNext;

			for (int i = 1; i < SIZE; i++) {

				cout << "i: " << i << endl;

				long long curr = input % 10;
				input /= 10;

				ptr->val = curr;

				if (i + 1 >= SIZE)
					break;

				ListNode *next = new ListNode(-1);
				ptr->next = next;

				ptr = next;

				cout << "curr: " << curr << endl;
				cout << "input: " << input << endl << endl;

			}

			ptr->next = NULL;

			return toReturn;

		};

		long long linkedListToInt(ListNode* l1) {

			ListNode *ptr = l1;

			long long toReturn = 0;
			long long multiplier = 1;
			while (ptr->next != NULL) {

				long long val = ptr->val;
				cout << "val: " << val << endl;
				val *= multiplier;
				cout << "val *= multiplier;: " << val << endl;
				toReturn += val;
				cout << "toReturn: " << toReturn << endl;

				multiplier *= 10;

				cout << "multiplier: " << multiplier << endl << endl;


				ptr = ptr->next;

			}

			long long val = ptr->val;
			cout << "val: " << val << endl;
			val *= multiplier;
			cout << "val *= multiplier;: " << val << endl;
			toReturn += val;
			cout << "toReturn: " << toReturn << endl;

			multiplier *= 10;

			cout << "multiplier: " << multiplier << endl << endl;

			return toReturn;

		};

};