#include <iostream>
#include <vector>

using namespace std;

int edit(string a, string b, int n, int m) {
    int M [n+1][m+1];

    // init
    for (int i = 0; i <= n; ++i)
        M[i][0] = i;
    for (int i = 0; i <= m; ++i)
        M[0][i] = i;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            M[i][j] = min(min(M[i-1][j] + 1, M[i][j-1] + 1), M[i-1][j-1] + ((a[i-1] == b[j-1]) ? 0 : 1));

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

        cout << edit(a,b,n,m) << endl;
    }

    return 0;
}