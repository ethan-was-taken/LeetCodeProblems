#include <iostream>
#include <vector>
#include <set>
#include <algorithm>


using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

struct comparison {
	inline bool operator() (const Interval& struct1, const Interval& struct2) {
		return struct1.start < struct2.start;
	}
};

// Help from: https://stackoverflow.com/questions/1380463/sorting-a-vector-of-custom-objects
// Solution
class mergeIntervals {
	public:
		vector<Interval> merge(vector<Interval>& intervals) {

			if (intervals.empty())
				return vector<Interval>();
						
			// Average case complexity O(nlogn)
			// If you want a faster sort, you could implement 
			//   your own radix sort to get O(nk) complexity
			//sort(intervals.begin(), intervals.end(), comparison());
			sort(intervals.begin(), intervals.end(), comparison());

			vector<Interval> toReturn;
			toReturn.push_back(intervals[0]);

			for (int i = 1; i < intervals.size(); i++) {

				if (toReturn.back().end < intervals[i].start) 
					toReturn.push_back( intervals[i] );
				else
					toReturn.back().end = max(toReturn.back().end, intervals[i].end);

			}
			
			return toReturn;
		};
};