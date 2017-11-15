/*
use dynamic programming algorithm to solve 01pack problem

@author racaljk
@version 1.0
*/

#include <iostream>
#include <algorithm>

int totalWeight;
int weight[1024];
int value[1024];
int dp[1024][1024];
int n;

void dpSolution() {
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= totalWeight; k++) {
            if (weight[i] <= k) {
                dp[i][k] = std::max(dp[i - 1][k], dp[i - 1][k - weight[i]] + value[i]);
            }
            else {
                dp[i][k] = dp[i - 1][k];
            }
        }
    }
}

int main() {
    std::cout << "Input how many objects you have:\n";
    std::cin >> n;
    std::cout << "Input the weight value pair of each obejct(split with /space/):\n";
    for (int i = 1; i <= n; i++) {
        std::cin >> weight[i] >> value[i];
    }
    std::cout << "Input maximum limit of your pocket:\n";
    std::cin >> totalWeight;
    dpSolution();
    std::cout << "Max value: " << dp[n][totalWeight] << "\n";
    return 0;
}