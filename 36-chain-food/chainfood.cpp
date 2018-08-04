#include <iostream>
#include <vector>
#include <algorithm>
#include "unionfind.h"

using namespace std;

struct Animal {
    int species;
    bool unassigned;
    Animal() {
        species = 0;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t-- > 0) {
        int n, k;
        cin >> n >> k;

        UnionFind<Animal*> uf;
        while (n-- > 0) {
            uf.MakeSet(new Animal);
        }

        vector<UnionFind<Animal*>::Node*> forest = uf.Forest();

        int counter = 0;
        for (int i = 0; i < k; i++) {
            int type, s, d;
            cin >> type >> s >> d;

            if (s > n || s < 1 || d > n || d < 1 || (s == d && type == 2)) {
                counter++;
                continue;
            }

            UnionFind<Animal*>::Node* nodeS = forest[s-1];
            UnionFind<Animal*>::Node* nodeD = forest[d-1];

            nodeS = uf.Find(nodeS);
            nodeD = uf.Find(nodeD);

            if (type == 1) {
                if (nodeS->data->species != nodeD->data->species) {
                    counter++;
                    continue;
                }
                uf.Union(nodeS, nodeD);
            } else {
                if (nodeS == nodeD) {
                    counter++;
                    continue;
                }

                
                
                if (nodeD->data->species != nodeS->data->species + 1 % 3) {
                    counter++;
                    continue;
                }
                
            }
        }
    }


    return 0; 
}