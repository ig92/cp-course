#include <iostream>
#include <vector>

#define WHITE 0
#define BLACK 1

using namespace std;

struct Node {
    vector<Node*> children;
    int when_taken;
    int when_not_taken;
    int state;
};

void vcover(Node * root) {
    root->state = BLACK;

    // compute if needed something
    root->when_taken = 1;
    for (int i = 0; i < root->children.size(); ++i) {
        Node * child = root->children[i];
        if (child->state == BLACK)
            continue;
        vcover(child);
        root->when_not_taken += child->when_taken;
        root->when_taken += min(child->when_not_taken, child->when_taken);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    vector<Node> nodes (n);

    for(int i = 0; i < n; ++i)
        nodes[i].state = WHITE;

    for (int i = 0; i < n-1; ++i) {
        int u,v;
        cin >> u >> v;
        nodes[u-1].children.push_back(&nodes[v-1]);
        nodes[v-1].children.push_back(&nodes[u-1]);
    }

    vcover(&nodes[0]);

    cout << min(nodes[0].when_taken, nodes[0].when_not_taken) << endl;
    
    return 0;
}
