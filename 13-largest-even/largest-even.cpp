#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    cin.ignore();

    while (t-- > 0) {
        string number;
        cin >> number;

        vector<int> counters (10);
        int minEven = 10;
        for (int i = 0; i < number.length(); ++i) {
            int n = number[i] - '0';
            if (n % 2 == 0 && minEven > n)
                minEven = n;
            counters[n]++;
        }

        // if no even numbers
        if (minEven < 10)
            counters[minEven]--;

        for (int i = 9; i >= 0; --i)
            while (counters[i]-- > 0)
                cout << i;

        if (minEven < 10)
            cout << minEven;
        
        cout << endl;
    }
    
    return 0;
}
