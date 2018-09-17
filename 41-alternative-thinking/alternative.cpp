#include <iostream>

using namespace std;

#define ZERO(x) ((x-'0')==1)

int main() {
    std::ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    cin.ignore();
    string sequence;
    getline(cin, sequence);

    bool last = ZERO(sequence[0]);
    int counter = 1;
    for (int i = 1; i < n; ++i) {
        if (ZERO(sequence[i]) != last) {
            last = !last;
            counter++;
        }
    }

    cout << min(n, counter + 2) << endl;

    return 0;
}