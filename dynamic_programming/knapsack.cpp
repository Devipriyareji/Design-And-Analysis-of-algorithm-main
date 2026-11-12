#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int itemCount;
    int capacity;

    cout << "Enter the number of items: ";
    if (!(cin >> itemCount) || itemCount <= 0) {
        cout << "Number of items must be positive.\n";
        return 1;
    }

    cout << "Enter the knapsack capacity: ";
    if (!(cin >> capacity) || capacity < 0) {
        cout << "Capacity cannot be negative.\n";
        return 1;
    }

    vector<int> weights(itemCount);
    vector<int> values(itemCount);

    cout << "Enter each item's weight and value:\n";
    for (int i = 0; i < itemCount; ++i) {
        if (!(cin >> weights[i] >> values[i]) || weights[i] <= 0 || values[i] < 0) {
            cout << "Weights must be positive and values cannot be negative.\n";
            return 1;
        }
    }

    // dp[c] stores the maximum value attainable with capacity c.
    vector<long long> dp(capacity + 1, 0);

    for (int i = 0; i < itemCount; ++i) {
        for (int currentCapacity = capacity; currentCapacity >= weights[i]; --currentCapacity) {
            dp[currentCapacity] = max(
                dp[currentCapacity],
                dp[currentCapacity - weights[i]] + values[i]
            );
        }
    }

    cout << "Maximum value: " << dp[capacity] << '\n';
    return 0;
}
