#include <iostream>
#include <vector>

using namespace std;

int numbers [101];

bool knapsack(int c, int n) {
    bool M [n+1][c+1];

    // init
    for (int i = 0; i <= c; ++i)
        M[0][i] = false;
    for (int i = 0; i <= n; ++i)
        M[i][0] = true;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= c; ++j)
            M[i][j] = (M[i-1][j] || (j >= numbers[i-1] && M[i-1][j-numbers[i-1]]));

    return M[n][c];
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        for(int i = 0; i < n; ++i) 
            cin >> numbers[i];

        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += numbers[i];

        if (sum % 2 != 0) {
            cout << "NO" << endl;
            continue;
        }
        
        int target = sum / 2;

        if (knapsack(target, n) == 0)
            cout << "NO" << endl;
        else 
            cout << "YES" << endl;

        
    }
    
    return 0;
}

