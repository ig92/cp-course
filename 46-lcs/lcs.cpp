#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lcs(string a, string b, int n, int m) {
    int M [n+1][m+1];

    // init
    for (int i = 0; i <= n; ++i) {
        M[i][0] = 0;
    }
    for (int i = 0; i <= m; ++i) {
        M[0][i] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            M[i][j] = max(max(M[i-1][j], M[i][j-1]), M[i-1][j-1] + ((a[i-1] == b[j-1]) ? 1 : 0));
        }
    }

    return M[n][m];
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t-- > 0) {
        int n, m;
        cin >> n >> m;

        string a, b;
        cin >> a >> b;

        cout << lcs(a,b,n,m) << endl;
    }
    return 0;
}

