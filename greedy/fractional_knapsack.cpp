#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct Item {
    double weight;
    double value;
};

int main() {
    int itemCount;
    double capacity;

    cout << "Enter the number of items: ";
    if (!(cin >> itemCount) || itemCount <= 0) {
        cout << "Number of items must be positive.\n";
        return 1;
    }

    cout << "Enter the knapsack capacity: ";
    if (!(cin >> capacity) || capacity <= 0) {
        cout << "Capacity must be positive.\n";
        return 1;
    }

    vector<Item> items(itemCount);
    cout << "Enter each item's weight and value:\n";
    for (Item &item : items) {
        if (!(cin >> item.weight >> item.value) ||
            item.weight <= 0 || item.value < 0) {
            cout << "Weights must be positive and values cannot be negative.\n";
            return 1;
        }
    }

    sort(items.begin(), items.end(), [](const Item &a, const Item &b) {
        return a.value / a.weight > b.value / b.weight;
    });

    double totalValue = 0;
    double remainingCapacity = capacity;
    cout << fixed << setprecision(2);
    cout << "\nItems selected (weight taken / value):\n";

    for (const Item &item : items) {
        if (remainingCapacity <= 0)
            break;

        double weightTaken = min(item.weight, remainingCapacity);
        double fraction = weightTaken / item.weight;
        double valueTaken = fraction * item.value;
        totalValue += valueTaken;
        remainingCapacity -= weightTaken;

        cout << weightTaken << " / " << valueTaken << '\n';
    }

    cout << "Maximum value: " << totalValue << '\n';
    return 0;
}
