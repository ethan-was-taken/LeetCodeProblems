#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

class twoSum {
	public:
		//ctor
		twoSum() {};
		//dtor
		~twoSum() {};

		vector<int> two_sum(vector<int>& nums, int target) {
			
			arrayToMap(nums);
			int indexOne = 0;
			int indexTwo = 0;

			typedef std::multimap<int, int>::iterator it_type;
			for (it_type ent1 = numsHashMap.begin(); ent1 != numsHashMap.end(); ent1++) {

				int newTarget = target - ent1->first;
				indexOne = ent1->second;

				cout << "------------" << endl;
				cout << "newTarget: " << newTarget << endl;
				cout << "ent1->first: " << ent1->first << endl;
				cout << "ent1->second: " << ent1->first << endl;				

				multimap<int, int>::iterator ent2 = numsHashMap.find(newTarget);
				if ( ent2 != numsHashMap.end() && 
					(ent2->first != ent1->first || ent2->second != ent1->second) ) {
					indexTwo = ent2->second;
					cout << "ent2->first: " << ent2->first << endl;
					cout << "ent2->second: " << ent2->second << endl;
					cout << "-----1------" << endl << endl;
					break;
				}
				cout << "ent2 == .end() " << endl;
				cout << "-----2------" << endl << endl;
			}


			vector<int> toReturn;
			toReturn.push_back(indexOne);
			toReturn.push_back(indexTwo);
			sort(toReturn.begin(), toReturn.end());
			return toReturn;


		};

	private:
		//----------Fucntions----------
		void arrayToMap(vector<int>& arr) {
			for (unsigned int i = 0; i < arr.size(); i++)
				numsHashMap.insert( pair<int,int>( arr[i], i ) );
		};

		//----------GlobalVar----------
		// first int is the number
		// second int is the index from the array
		multimap<int, int> numsHashMap;

};

