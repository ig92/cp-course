#include <iostream>
#include <string>

using namespace std;

int kmp(string p, string t) {
    // pattern preprocessing
    int pp [p.length()];
    pp[0] = 0;
    int i = 1, j = 0;
    while (i < p.length()) {
        if (p[j] == p[i])
            pp[i++] = ++j;
        else if (j == 0) 
            pp[i++] = 0;
        else 
            j = pp[j-1];
    }

    // kmp
    i = 0;
    j = 0;
    int shifts = -1;
    int best_j = -1;
    while(i < t.length() && j < p.length()) {
        if (t[i] != p[j]) {
            if (j == 0) i++;
            else j = pp[j-1];
        } else {
            if (t[i] == p[j]) i++, j++;
            if (j > best_j) {
                best_j = j;
                shifts = i-j;
            }
        }
    }

    return shifts;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    string A;
    string B;

    cin >> n;

    cin >> A >> B;

    B = B + B;

    cout << kmp(A,B) << endl;

    return 0;
}