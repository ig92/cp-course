#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Suffix {
    int index;
    int rank;
    int nextRank;
};

int cmp(Suffix a, Suffix b) {
    // if the ranks are equal, compare next ranks
    if (a.rank == b.rank)
        return a.nextRank < b.nextRank;
    return a.rank < b.rank;
}

// O(n logn logn) solution
vector<int> buildSuffixArray(string s, int n) {
    // A structure to store suffixes and their indexes
    Suffix suffixes[n];

    for (int i = 0; i < n; i++) {
        suffixes[i].index = i;
        suffixes[i].rank = s[i] - 'A';
        suffixes[i].nextRank = -1;
        if (i < n-1)
            suffixes[i].nextRank = (s[i+1] - 'A');
    }

    // sort suffixes
    sort(suffixes, suffixes + n, cmp);

    int inv[n];
    for (int k = 4; k < n; k *= 2) {
        int rank = 0;
        int prevRank = suffixes[0].rank;
        suffixes[0].rank = rank;
        inv[suffixes[0].index] = 0;

        // update rank
        for (int i = 1; i < n; ++i) {
            if (suffixes[i].rank != prevRank || suffixes[i].nextRank != suffixes[i-1].nextRank)
                rank++;
            prevRank = suffixes[i].rank;
            suffixes[i].rank = rank;

            inv[suffixes[i].index] = i;
        }

        // update nextRank
        for (int i = 0; i < n; ++i) {
            int nextIndex = suffixes[i].index + k / 2;
            suffixes[i].nextRank = -1;
            if (nextIndex < n)
                suffixes[i].nextRank = suffixes[inv[nextIndex]].rank;
        }

        // sort suffixes
        sort(suffixes, suffixes + n, cmp);
    }

    // build suffix array
    vector<int> suffixArr;
    for (int i = 0; i < n; ++i)
        suffixArr.push_back(suffixes[i].index);

    return suffixArr;
}

vector<int> buildLCP(string s, vector<int> suffixArr) {
    int n = suffixArr.size();
    vector<int> lcp(n, 0);

    // build inverted index
    int inv[n];
    for (int i = 0; i < n; ++i)
        inv[suffixArr[i]] = i;

    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (inv[i] == n-1) {
            k = 0;
            continue;
        }

        // next substring in sorted suffixArr
        int j = suffixArr[inv[i]+1];

        // match from kth index on
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;

        lcp[inv[i]] = k;

        if (k > 0)
            k--;
    }

    return lcp;
}

int countSubstrings(string s) {
    int n = s.length();
    
    // build suffix array and lcp array
    vector<int> suffixArr = buildSuffixArray(s, n);
    vector<int> lcp = buildLCP(s, suffixArr);

    int result = n * n;
    // int sum = (n * n - n) / 2;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += i;

    result -= sum;

    for (int i = 0; i < n-1; i++)
        result -= lcp[i];

    return result;
}

int main() {
    int t;
    cin >> t; cin.ignore();

    int ans[t];
    while (t-- > 0) {
        string s;
        cin >> s; cin.ignore();
        ans[t] = countSubstrings(s);
    }

    for (int i = sizeof(ans) / sizeof(int) - 1; i > -1 ; --i) {
        cout << ans[i] << endl;
    }

    return 0;
}
