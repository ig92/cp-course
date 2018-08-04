#include <vector>
#include <iostream>

using namespace std;

template<typename T> class UnionFind {
public:
    struct Node {
        T data;
        int rank;
        int forestIndex;
        Node* parent;
        Node(T _data, int _forestIndex) {
            data = _data;
            rank = 0;
            forestIndex = _forestIndex;
            parent = this;
        }
    };

    UnionFind() {
          
    }

    Node* MakeSet(T data) {
        Node* newNode = new Node(data, forest.size());
        forest.push_back(newNode);
        return newNode;
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

private:
    vector<Node*> forest;
};
