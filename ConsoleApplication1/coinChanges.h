#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

#include "stopper.h"
#include "printer.h"

using namespace std;

class coinChanges {
public:
	static int coinChange(vector<int>& coins, int amount) {
		/*
							Find optimal solution for 1,2,3,4,...
		0.	sort coins
			go through dp[coins[i]]	and make it 1 -> rest is INT_MAX
		1.	for(smallestCoin -> amnt)
			a. for(smallestCoin -> largest)
					if(!dfs(i - coins[j], i, i))
						break
		2.	dfs(int tempAmnt, int amnt, int start, int numCoins)
			a.	if(tempAmnt < smallestCoin) 
					return false;
			b.	else if(tempAmnt == 0)
					dp[amnt] = min(dp[amnt], numCoins)
					return true;
			c.	else if(dp[tempAmnt] has a value)
					dp[amnt] = min(dp[amnt], dp[tempAmnt] + 1);
					return true
			d.	else // We're at an invalid value
					return true				
		*/

		sort(coins.begin(), coins.end());
		vector<int> dp(amount + 1, INT_MAX);
		for (int curr : coins)
			dp[curr] = 1;
		
		for (int i = coins[0]; i <= amount; i++) {
			for (int j = 0; j < coins.size(); j++) {
				int tempAmount = i - coins[j];
				tempAmount = (tempAmount < 0) ? 0 : tempAmount;
				if (!hasChange(coins, dp, tempAmount, amount, dp[tempAmount], i)) {
					break;
				}
			}
		}

		return dp.back();

	};

private:
	static bool hasChange(vector<int> &coins, vector<int> &dp, int tempAmnt, int amnt, int numCoins, int currCoin) {

		print(dp, currCoin);
		cout << "coins[0]\t" << coins[0] << endl;
		cout << "tempAmnt:\t" << tempAmnt << endl;
		cout << "amnt\t\t" << amnt << endl;
		cout << "numCoins\t" << numCoins << endl;

		if (tempAmnt < coins[0]) {
			cout << "tempAmnt < smallestCoin" << endl;
			cout << "returning false" << endl;
			stopper::stop();
			return false;
		}
		else if (tempAmnt == 0) {
			cout << "tempAmnt == 0" << endl;
			dp[amnt] = min(dp[amnt], numCoins);
		}
		else if (dp[tempAmnt] != INT_MAX) {
			cout << "dp[tempAmnt] has a value" << endl;
			dp[currCoin] = min(dp[currCoin], dp[tempAmnt] + 1);
		}

		// We're at an invalid value
		cout << "returning true" << endl;
		stopper::stop();
		return true;
	}

	static void print(vector<int> ans, int index) {
		
		for (int i = 0; i < ans.size(); i++)
			cout << setw(3) << left << i;
		cout << endl;

		for (auto i : ans) {
			if (i == INT_MAX || i == INT_MIN)
				cout << setw(3) << left << "_";
			else
				cout << setw(3) << left << i;
		}
		cout << endl;

		for (int i = 0; i < index; i++)
			cout << setw(3) << left << " ";
		cout << setw(3) << left << "^" << endl;

	};

};