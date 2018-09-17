#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int degree;
    int xsum;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<Node> nodes (n);
    queue<int> leaves;
    int counter = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i].degree >> nodes[i].xsum;
        if (nodes[i].degree == 1)
            leaves.push(i);
        counter += nodes[i].degree;
    }
    
    cout << counter / 2 << endl;
    while (!leaves.empty()) {
        int id = leaves.front();
        leaves.pop();
        if (nodes[id].degree < 1) {
            continue;
        }
        nodes[nodes[id].xsum].xsum ^= id;
        nodes[nodes[id].xsum].degree--;
        if (nodes[nodes[id].xsum].degree == 1)
            leaves.push(nodes[id].xsum);
        cout << id << " " << nodes[id].xsum << endl;
    }

    return 0;
}