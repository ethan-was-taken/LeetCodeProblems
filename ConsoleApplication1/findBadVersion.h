#pragma once
#include <iostream>
#include <algorithm>

#include "printer.h"

using namespace std;


class findBadVersion {
public:
	static bool isBadVersion(int version) {
		return version >= 1702766719;
	};

	static int firstBadVersion(int n) {

		long long start = 1;
		long long end = n;
		while (start < end) {

			int mid = (end + start) / 2;

			cout << "start:\t" << start << endl;
			cout << "end:\t" << end << endl;
			cout << "mid:\t" << mid << endl;
			cout << "isBad:\t";
			printer::print(isBadVersion(mid));
			cout << endl;
			stopper::stop();

			if (isBadVersion(mid))
				end = mid - 1;
			else
				start = mid + 1;		

		}

		return (!isBadVersion(start)) ? start + 1 : start;

	};

};