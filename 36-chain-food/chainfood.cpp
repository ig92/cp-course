#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Animal {
    int id;
    int species;
    Animal(int _id) {
        id = _id;
    }
};


struct Node {
    Animal * data;
    int rank;
    Node* parent;
    Node(Animal * _data) {
        data = _data;
        rank = 0;
        parent = this;
    }
};

class UnionFind {
public:
    void MakeSet(Node * node) {
        forest.push_back(node);
    }

    // Union by Rank, if equal y becomes root
    void Union(Node* x, Node* y) {
        Node* rootX = Find(x);
        Node* rootY = Find(y);

        if (rootX->rank > rootY->rank) {
            rootY->parent = rootX;
            return;
        }

        rootX->parent = rootY;
        if (rootX->rank == rootY->rank)
            rootY->rank++;
    }

    // Find with Path Compression
    Node* Find(Node* x) {
        if (x->parent != x)
            x->parent = Find(x->parent);
        return x->parent;
    }

    vector<Node*> Forest() {
        return forest;
    }

    int Relation(Node * i, Node * j) {

    }

private:
    vector<Node*> forest;
};

int main() {
    std::ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t-- > 0) {
        int n, k;
        cin >> n >> k;

        vector<Node*> nodes (n);

        UnionFind uf;
        for (int i = 0; i < n; ++i) {
            Node * n = new Node(new Animal(i));
            nodes[i] = n;
            uf.MakeSet(n);
        }

        int counter = 0;
        while (k-- > 0) {
            int type, i, j;
            cin >> type >> i >> j;

            if (i > n || j > n) {
                counter++;
                continue;
            }

            Node * inode = nodes[i];
            Node * jnode = nodes[j];

            if (type == 1) {
                // i and j should be the same
                int relation = uf.Relation(inode, jnode);
                
            } else {
                // i should eat j
            }
        } 

    }


    return 0; 
}