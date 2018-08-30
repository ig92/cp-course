#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

template<typename T>
vector<T> get_input_sequence(size_t n) {
    vector<T> sequence(n);

    for(size_t i = 0; i < n; ++i) 
        cin >> sequence[i];
    return sequence;
}

struct Node {
    int index;
    int lowlink;
    int cost;
    int sccID;
    bool onStack;
    vector<int> neighbors;
};

int nSCC = 0;
int IDX = 0;
stack<int> s;
vector<Node> nodes;

void scc(int i) {
    nodes[i].index = IDX;
    nodes[i].lowlink = IDX;
    IDX++;
    s.push(i);
    nodes[i].onStack = true;

    for (int j = 0; j < nodes[i].neighbors.size(); j++) {
        int next = nodes[i].neighbors[j];
        if (nodes[next].index == -1) {
            scc(next);
            nodes[i].lowlink = min(nodes[i].lowlink, nodes[next].lowlink);
        } else if (nodes[next].onStack) {
            nodes[i].lowlink = min(nodes[i].lowlink, nodes[next].index);
        }
    }

    // if node is the root of scc
    if (nodes[i].index == nodes[i].lowlink) {
        int next;
        do {
            next = s.top();
            s.pop();
            nodes[next].onStack = false;
            nodes[next].sccID = nSCC;
        } while (nodes[i].index != nodes[next].index);
        nSCC++; 
    }
}

void tarjan() {
    for (int i = 0; i < nodes.size(); ++i)
        if (nodes[i].index == -1) // not yet discovered
            scc(i);
}

int main() {
    std::ios_base::sync_with_stdio(false);

    // read nodes
    int n;
    cin >> n;
    vector<int> costs = get_input_sequence<int>(n);
    for (int i = 0; i < n; i++) {
        Node n;
        n.cost = costs[i];
        n.index = -1;
        nodes.push_back(n);
    }

    // read edges
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        nodes[x-1].neighbors.push_back(y-1);
    }
    
    // find strongly connected components
    tarjan();

    // pay for each scc the minimum cost
    vector<int> min (nSCC, 1e9);    
    for (int i = 0; i < n; ++i) {
        Node n = nodes[i];
        if (n.cost < min[n.sccID])
            min[n.sccID] = n.cost;
    }

    // total cost
    uint64_t sum = 0;
    for (int i = 0; i < nSCC; ++i)
        sum += min[i];

    // compute number of ways
    vector<int> ways (nSCC, 0);
    for (int i = 0; i < n; ++i) {
        Node n = nodes[i];
        if (n.cost == min[n.sccID])
            ways[n.sccID]++;
    }

    // total number of ways
    uint64_t totWays = 1;
    for (int i = 0; i < nSCC; ++i)
        totWays *= ways[i];

    cout << sum << " " << (totWays % 1000000007) << endl;

    return 0;
}