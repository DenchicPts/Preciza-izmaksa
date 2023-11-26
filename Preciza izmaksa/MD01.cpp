#pragma once

#include "quests.h"

// Funkcija, lai atrastu dažādos izmaksas variantus
int countWays(vector<int>& coins, int amount) {
	vector<int> result(amount + 1, 0);
	result[0] = 1;

	for (int coin : coins) {
		for (int i = coin; i <= amount; ++i) {
			result[i] += result[i - coin];
		}
	}
	return result[amount];
}

vector<int> findOptimalWay(vector<int>& coins, int amount) {
	vector<int> optimalCount(coins.size(), 0);
	vector<long long> dp(amount + 1, INT_MAX);
	dp[0] = 0;
	for (int coin : coins) {
		for (int i = coin; i <= amount; ++i) {
			if (dp[i - coin] + 1 < dp[i]) {
				dp[i] = dp[i - coin] + 1;
			}
		}
	}

	// Извлекаем оптимальный способ размена

	for (int i = coins.size() - 1; i >= 0; --i) {
		while (amount >= coins[i] && dp[amount - coins[i]] + 1 <= dp[amount]) {
			dp[amount] = dp[amount - coins[i]] + 1;
			optimalCount[i]++;
			amount -= coins[i];
		}
	}
	return optimalCount;
}

void MD01() {
	vector<int> coins = { 2, 5, 9 };

	vector<int> sums = { 3018, 5759, 516 };


	for (const auto& sum : sums)
	{
		vector<int> optimalCount = findOptimalWay(coins, sum);
		cout << "Summa = " << sum << " - " << countWays(coins, sum) << " variantus, "
			<< "optimalais ";
		for (auto i = 0; i < coins.size(); ++i)
		{
			cout << optimalCount[i] << "x" << coins[i] << (i == coins.size() - 1 ? " " : " + ");
		}

		cout << endl;
	}

}