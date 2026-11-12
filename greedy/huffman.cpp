#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node {
    char symbol;
    long long frequency;
    Node *left;
    Node *right;

    Node(char symbol, long long frequency)
        : symbol(symbol), frequency(frequency), left(nullptr), right(nullptr) {}
};

struct CompareNodes {
    bool operator()(const Node *a, const Node *b) const {
        return a->frequency > b->frequency;
    }
};

void printCodes(const Node *node, const string &code) {
    if (node == nullptr)
        return;

    if (node->left == nullptr && node->right == nullptr) {
        cout << node->symbol << ": " << (code.empty() ? "0" : code) << '\n';
        return;
    }

    printCodes(node->left, code + '0');
    printCodes(node->right, code + '1');
}

void deleteTree(Node *node) {
    if (node == nullptr)
        return;

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int main() {
    int symbolCount;
    cout << "Enter the number of symbols: ";
    if (!(cin >> symbolCount) || symbolCount <= 0) {
        cout << "Number of symbols must be positive.\n";
        return 1;
    }

    priority_queue<Node *, vector<Node *>, CompareNodes> minHeap;
    cout << "Enter each symbol and its frequency:\n";

    for (int i = 0; i < symbolCount; ++i) {
        char symbol;
        long long frequency;
        if (!(cin >> symbol >> frequency) || frequency <= 0) {
            cout << "Frequencies must be positive.\n";
            while (!minHeap.empty()) {
                deleteTree(minHeap.top());
                minHeap.pop();
            }
            return 1;
        }
        minHeap.push(new Node(symbol, frequency));
    }

    while (minHeap.size() > 1) {
        Node *left = minHeap.top();
        minHeap.pop();
        Node *right = minHeap.top();
        minHeap.pop();

        Node *parent = new Node('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        minHeap.push(parent);
    }

    cout << "\nHuffman codes:\n";
    printCodes(minHeap.top(), "");
    deleteTree(minHeap.top());
    return 0;
}
