#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class countPrimes_204 {
public:
	/*
	1.	make array of bools, size n

	2.	loop through array starting at 2	
			
			if(!arr[i])
				continue

			numPrimes++
			
			for(int curr = i * 2; curr <= n; curr += i)
				arr[curr] = false

	3.	return numPrimes
	*/
	int countPrimes(int n) {

		vector<bool> isPrime(n + 1, true);
		int numPrimes = 0;

		for (int i = 2; i < isPrime.size(); i++) {

			if (!isPrime[i]) {
				cout << i << " is prime" << endl;
				cout << "-------------------------------" << endl;
				continue;
			}

			numPrimes++;

			for (int curr = i * 2; curr < isPrime.size(); curr += i) {
				isPrime[curr] = false;
			}

			print(isPrime);
		
		}

		return (numPrimes - 1 < 0) ? 0 : numPrimes - 1;

	};

private:
	void print(vector<bool> &primes) {

		for (int i = 2; i < primes.size(); i++) {
			
			if (primes[i])
				cout << i << "\t";

		}
		cout << endl;

		int stop;
		cout << "\t\t\t\t\t";
		cin >> stop;
		
		cout << "-------------------------------" << endl;

	}

};