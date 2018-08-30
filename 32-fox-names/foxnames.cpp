#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define I(X) X-'a'
#define WHITE 0
#define GREY 1
#define BLACK 2

int G[26][26];
vector<int> letters (26);
string output;

bool dfs(int i) {
    if (letters[i] == BLACK)
        return true;
    if (letters[i] == GREY)
        return false;

    letters[i] = GREY;

    for (int j = 0; j < 26; ++j)
        if (G[i][j] == 1 && !dfs(j))
            return false;

    letters[i] = BLACK;

    output = char(i+'a') + output;

    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cin.ignore();

    vector<string> names (n);

    for (int i = 0; i < n; ++i)
        getline(cin, names[i]);

    for (int k = 0; k < n-1; k++) {
        string current = names[k];
        string next = names[k+1];

        // find leftmost position where chars differ
        int i = 0;
        while (i < current.length() && i < next.length() && current[i] == next[i])
            i++;
        
        // if the first string has been processed
        // then it is okay and we just move forward
        if (i == current.length())
            continue;

        // no cases like:
        // rivest
        // rives
        if (i == next.length()) {
            cout << "Impossible" << endl;
            return 0;
        }

        G[I(current[i])][I(next[i])] = 1;
    }

    for (int i = 0; i < 26; ++i) {
        if (letters[i] == WHITE && !dfs(i)) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    cout << output << endl;

    return 0;
}