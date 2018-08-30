#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;

        getline(cin, str);

        int n = str.length();

        int M [n+1][n+1];

        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j)
                M[i][j] = -1;
            M[i][i] = 1;
            if (i > 0)
                M[i][i-1] = 0;
        }

        for (int i = n-1; i > 0; --i) {
            for (int j = i+1; j <= n; ++j) {
                if (str[i-1] == str[j-1])
                    M[i][j] = 2 + M[i+1][j-1];
                M[i][j] = max(M[i][j], max(M[i+1][j], M[i][j-1]));
            }
        }

        cout << M[1][n] << endl;
    }

    return 0;
}

