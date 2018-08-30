#include <iostream>
#include <vector>

using namespace std;
#define LEFT 0
#define RIGHT 1

struct Tree {
    int pos;    // position
    int hgt;    // height
    bool cut;
    int side;
};

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<Tree> trees (n);
    for (int i = 0; i < n; ++i)
        cin >> trees[i].pos >> trees[i].hgt;

    int counter = 0;

    for (int i = 0; i < n; ++i) {
        // special cases
        if (i == 0 || i == n-1) {
            trees[i].cut = true;
            trees[i].side = (i == 0) ? LEFT : RIGHT;
            counter++;
            continue;
        }

        if (trees[i-1].pos < trees[i].pos - trees[i].hgt) {
            if (trees[i-1].side == LEFT || !trees[i-1].cut || ((trees[i-1].pos + trees[i-1].hgt) < (trees[i].pos - trees[i].hgt))) {
                trees[i].cut = true;
                trees[i].side = LEFT;
                counter++;
                continue;
            }
        }

        if (trees[i+1].pos > trees[i].pos + trees[i].hgt) {
            trees[i].cut = true;
            trees[i].side = RIGHT;
            counter++;
            continue;
        }
    }

    cout << counter << endl;
    return 0;
}