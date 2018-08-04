#include <iostream>
#include <vector>
#include <algorithm>

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

        if (rootX == rootY) {
            return;
        }

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

struct Edge {
    int i;
    int j;
    int w;
    Edge(int _i, int _j, int _w) {
        i = _i;
        j = _j;
        w = _w;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<Edge*> edges;
    for (int e = 0; e < m; e++) {
        int i, j, w;
        cin >> i >> j >> w;
        edges.push_back(new Edge(i,j,w));
    }

    sort(edges.begin(), edges.end(), [](Edge* e1, Edge* e2) {return e1->w < e2->w;});

    UnionFind<int> uf;

    vector<UnionFind<int>::Node*> nodes;
    for (int i = 0; i < n; i++) {
        nodes.push_back(uf.MakeSet(i));
    }

    uint64_t sum = 0;

    for (int i = 0; i < m; i++) {
        Edge* e = edges[i];
        UnionFind<int>::Node* u = nodes[e->i-1];
        UnionFind<int>::Node* v = nodes[e->j-1];
        if (uf.Find(u)->data != uf.Find(v)->data) {
            uf.Union(u,v);
            sum += e->w;
        }
    }

    cout << sum << endl;

    return 0; 
}