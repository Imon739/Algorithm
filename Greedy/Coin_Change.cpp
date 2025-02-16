#include <iostream>
#include <vector>

using namespace std;

vector<int> coinChangeGreedy(const vector<int>& denominations, int amount, vector<int>& coinsCount) {
    vector<int> result;
    int n = denominations.size();

    for (int i = n - 1; i >= 0; --i) {
        while (amount >= denominations[i]) {
            result.push_back(denominations[i]);
            amount -= denominations[i];
            coinsCount[i]++;
        }
    }

    return result;
}

int main() {
    vector<int> denominations = {1, 5, 10, 25};
    int amount = 173;

    vector<int> coinsCount(denominations.size(), 0);
    vector<int> coins = coinChangeGreedy(denominations, amount, coinsCount);

    cout << "Coins used for amount " << amount << ":" << endl;
    for (int i = 0; i < coins.size(); ++i) {
        if (coinsCount[i] > 0)
            cout << denominations[i] << " x " << coinsCount[i] << endl;
    }
    cout << endl;

    return 0;
}
