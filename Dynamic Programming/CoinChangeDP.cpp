#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int CoinChangeDP(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (i >= coin && dp[i - coin] != INF) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    //for(int i:dp) cout << i << " ";

    return dp[amount];
}

int main() {
    int target = 173;
    vector<int> coinValues = {1, 5, 10, 25};

    int minCoins = CoinChangeDP(target, coinValues);



    cout << "Minimum coins required for " << target << ": " << minCoins << endl;


    return 0;
}
