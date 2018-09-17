#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_SIZE 50002

<<<<<<< HEAD
// int suffix_arr [MAX_SIZE];
// int tmp_suffix_arr [MAX_SIZE];
// int rank_arr [MAX_SIZE];
// int tmp_rank_arr [MAX_SIZE];
// int freq_table [MAX_SIZE];

// void countingSort(int k, int n) {
//     // clear the frequency table for the counting sort
//     memset(freq_table, 0, sizeof freq_table);

//     // compute the frequencies of ranks
//     for (int i = 0; i < n; i++) {
//         int j = 0;
//         if (i + k < n)
//             j = rank_arr[i+k];
//         freq_table[j]++;
//     }

//     // excusive prefix sum
//     for (int i = 0, sum = 0; i < max(300, n); i++) {
//         int t = freq_table[i];
//         freq_table[i] = sum;
//         sum += t; 
//     }

//     // shuffle the suffix array if necessary
//     for (int i = 0; i < n; i++) {
//         int j = 0;
//         if (suffix_arr[i] + k < n)
//             j = rank_arr[suffix_arr[i] + k];
//         tmp_suffix_arr[freq_table[j]] = suffix_arr[i];
//         freq_table[j]++;
//     }
    
//     // update the real suffix array
//     for (int i = 0; i < n; i++)
//         suffix_arr[i] = tmp_suffix_arr[i];
// }


// void build_suffix_array(string text) {
//     int n = text.size();

//     for (int i = 0; i < n; i++) rank_arr[i] = text[i];
//     for (int i = 0; i < n; i++) suffix_arr[i] = i;

//     for (int k = 1; k < n; k <<= 1) {
//         countingSort(k, n); //actually radix sort:sort based on the second item
//         countingSort(0, n); // then (stable) sort based on the first item

//         int r = 0;
//         tmp_rank_arr[suffix_arr[0]] = r; // re-ranking; start from rank r = 0

//         // compare adjacent suffixes
//         for (int i = 1; i < n; i++) {
//             if (rank_arr[suffix_arr[i]] != rank_arr[suffix_arr[i-1]] || rank_arr[suffix_arr[i] + k] != rank_arr[suffix_arr[i-1] + k])
//                 r++;
//             tmp_rank_arr[suffix_arr[i]] = r;
//         }

//         // update the rank array
//         for (int i = 0; i < n; i++) {
//             rank_arr[i] = tmp_rank_arr[i];
//         }

//         if (rank_arr[suffix_arr[n-1]] == n-1) break; // nice optimization trick

//     }
// }

string text;
int n;
int order [MAX_SIZE];
int classes [MAX_SIZE];

void sortSingle() {
    int freq_table [300];
    for (int i = 0; i < 300; ++i) 
        freq_table[i] = 0;
    for (int i = 0; i < n; ++i)
        freq_table[text[i]]++;
    for (int i = 1; i < 300; ++i)
        freq_table[i] += freq_table[i-1];
    for (int i = n-1; i >= 0; --i) {
        int c = text[i];
        freq_table[c]--;
        order[freq_table[c]] = i;
    }
}

void computeClasses() {
    classes[order[0]] = 0;
    for (int i = 1; i < n; ++i) {
        classes[order[i]] = classes[order[i-1]];
        if (text[order[i]] != text[order[i-1]])
            classes[order[i]]++;
    }
}

void sortDouble(int l) {
    int freq_table [n];
    for (int i = 0; i < n; ++i) 
        freq_table[i] = 0;
    for (int i = 0; i < n; ++i)
        freq_table[classes[i]]++;
    for (int i = 1; i < n; ++i)
        freq_table[i] += freq_table[i-1];
    int newOrder [n];
    for (int i = n-1; i >= 0; --i) {
        int start = (order[i] - l + n) % n;
        int cl = classes[start];
        freq_table[cl]--;
        newOrder[freq_table[cl]] = start;
    }
    for (int i = 0; i < n; ++i)
        order[i] = newOrder[i];
}

void updateClasses(int l) {
    int newClass [n];
    newClass[order[0]] = 0;
    for (int i = 1; i < n; ++i) {
        int cur = order[i];
        int pre = order[i-1];
        int mid = (cur + l) % n;
        int midpre = (pre + l) % n;
        newClass[cur] = newClass[pre];
        if (classes[cur] != classes[pre] || classes[mid] != classes[midpre])
            newClass[cur]++;
    }
    for (int i = 0; i < n; ++i)
        classes[i] = newClass[i];
}

void build_suffix_array() {
    sortSingle();
    computeClasses();
    int l = 1;
    while (l < n) {
        sortDouble(l);
        updateClasses(l);
        l *= 2;
    }
}

int lcp_arr [MAX_SIZE];
void build_lcp_array(string text) {
    int n = text.length();
    // build inverted suffix array
    int inv_index [n];
    for (int i = 0; i < n; ++i)
        inv_index[order[i]] = i;
=======
int suffix_arr [MAX_SIZE];
int tmp_suffix_arr [MAX_SIZE];
int rank_arr [MAX_SIZE];
int tmp_rank_arr [MAX_SIZE];
int lcp_arr [MAX_SIZE];

int freq_table [MAX_SIZE];

void countingSort(int k, int n) {
    // clear the frequency table for the counting sort
    memset(freq_table, 0, sizeof freq_table);

    // compute the frequencies of ranks
    for (int i = 0; i < n; i++) {
        int j = 0;
        if (i + k < n)
            j = rank_arr[i+k];
        freq_table[j]++;
    }

    // excusive prefix sum
    for (int i = 0, sum = 0; i < max(300, n); i++) {
        int t = freq_table[i];
        freq_table[i] = sum;
        sum += t; 
    }

    // shuffle the suffix array if necessary
    for (int i = 0; i < n; i++) {
        int j = 0;
        if (suffix_arr[i] + k < n)
            j = rank_arr[suffix_arr[i] + k];
        tmp_suffix_arr[freq_table[j]] = suffix_arr[i];
        freq_table[j]++;
    }
    
    // update the real suffix array
    for (int i = 0; i < n; i++)
        suffix_arr[i] = tmp_suffix_arr[i];
}

void build_suffix_array(string text) {
    int n = text.size();

    for (int i = 0; i < n; i++) rank_arr[i] = text[i];
    for (int i = 0; i < n; i++) suffix_arr[i] = i;

    for (int k = 1; k < n; k <<= 1) {
        countingSort(k, n); //actually radix sort:sort based on the second item
        countingSort(0, n); // then (stable) sort based on the first item

        int r = 0;
        tmp_rank_arr[suffix_arr[0]] = r; // re-ranking; start from rank r = 0

        // compare adjacent suffixes
        for (int i = 1; i < n; i++) {
            if (rank_arr[suffix_arr[i]] != rank_arr[suffix_arr[i-1]] || rank_arr[suffix_arr[i] + k] != rank_arr[suffix_arr[i-1] + k])
                r++;
            tmp_rank_arr[suffix_arr[i]] = r;
        }

        // update the rank array
        for (int i = 0; i < n; i++) {
            rank_arr[i] = tmp_rank_arr[i];
        }

        if (rank_arr[suffix_arr[n-1]] == n-1) break; // nice optimization trick

    }
}

void build_lcp_array(string text) {
    int n = text.length();

    // build inverted suffix array
    int inv_index [n];
    for (int i = 0; i < n; ++i)
        inv_index[suffix_arr[i]] = i;
>>>>>>> 238e238462bc2e3afcec73152a8baa1fdac61909

    int k = 0;
    
    for (int i = 0; i < n; ++i) {
        // this suffix is the last one
        if (inv_index[i] == n-1) {
            k = 0;
            continue;
        }

        // take the next suffix in alphabetical order of this one
<<<<<<< HEAD
        int j = order[inv_index[i]+1];
=======
        int j = suffix_arr[inv_index[i]+1];
>>>>>>> 238e238462bc2e3afcec73152a8baa1fdac61909

        while (i + k < n && j + k < n && text[i+k] == text[j+k])
            k++;

        lcp_arr[inv_index[i]] = k;

        if (k > 0)
            k--;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    cin.ignore();

    string ans = "";
    while (t--) {
<<<<<<< HEAD
        string text;
        cin >> text;
        text += '$';
        int n = text.length();
=======
        string in;
        cin >> in;
        in += '$';
>>>>>>> 238e238462bc2e3afcec73152a8baa1fdac61909

        cin.ignore();

        // cout << str << endl;

<<<<<<< HEAD
        build_suffix_array();
        build_lcp_array(text);

        // for (int i = 0; i < n; ++i)
        //     cout << suffix_arr[i] << " ";
        // cout << endl;
        // for (int i = 0; i < n; ++i)
        //     cout << lcp_arr[i] << " ";
        // cout << endl;

        int result = n - order[0];
 
        for (int i = 1; i < lcp_arr.size(); i++)
    
            //  subtract lcp from the length of suffix
            result += (n - order[i]) - lcp_arr[i - 1];
    
        result++;  // For empty string
        return result;
=======
        build_suffix_array(in);
        build_lcp_array(in);

        int n = in.length()-1;
        n *= (n + 1);
        n /= 2;

        for (int i = 1; i < n; i++)
            n -= lcp_arr[i];
>>>>>>> 238e238462bc2e3afcec73152a8baa1fdac61909

        ans += to_string(n) + "\n";
    }

    cout << ans;

    return 0;
}
<<<<<<< HEAD
=======


// #include <iostream>
// #include <string>
// #include <algorithm>
// #include <vector>

// using namespace std;

// int suffix_arr [50002];
// int lcp_arr [50002];

// struct suffix {
//     int index;
//     int rank;
//     int next_rank;
//     int sort_id;
// };

// int cmp(suffix a, suffix b) {
//     return (a.rank == b.rank) ? a.next_rank <= b.next_rank : a.rank <= b.rank;
// }

// void build_suffix_array(string text) {
//     int n = text.length();
//     suffix suffixes [n];

//     // build suffixes
//     for (int i = 0; i < n; ++i) {
//         suffixes[i].index = i;
//         suffixes[i].rank = text[i] - 'A';
//         suffixes[i].next_rank = (i == (n-1)) ? -1 : text[i+1] - 'A';
//     }

//     sort(suffixes, suffixes + n, cmp);

//     // inverted index used for updating the next rank
//     int inv_index [n];

//     for (int i = 2; i < n; i *= 2) {
//         // set rank of the first suffix
//         int rank = 0;
//         int prev_rank = suffixes[0].rank;
//         suffixes[0].rank = rank;
//         inv_index[suffixes[0].index] = 0;
        
//         // update ranks
//         for (int j = 1; j < n; ++j) {
//             if (suffixes[j].rank != prev_rank || suffixes[j].next_rank != suffixes[j-1].next_rank)
//                 rank++;
//             prev_rank = suffixes[j].rank;
//             suffixes[j].rank = rank;
//             inv_index[suffixes[j].index] = j;
//         }

//         // update next ranks by using inverted index
//         for (int j = 0; j < n; ++j)
//             suffixes[j].next_rank = ((suffixes[j].index + i) < n) ? suffixes[inv_index[suffixes[j].index + i]].rank : -1;
        
//         sort(suffixes, suffixes + n, cmp);
//     }

//     for (int i = 0; i < n; ++i)
//         suffix_arr[i] = suffixes[i].index;    
// }

// void build_lcp_array(string text) {
//     int n = text.length();

//     // build inverted suffix array
//     int inv_index [n];
//     for (int i = 0; i < n; ++i)
//         inv_index[suffix_arr[i]] = i;

//     int k = 0;
    
//     for (int i = 0; i < n; ++i) {
//         // this suffix is the last one
//         if (inv_index[i] == n-1) {
//             k = 0;
//             continue;
//         }

//         // take the next suffix in alphabetical order of this one
//         int j = suffix_arr[inv_index[i]+1];

//         while (i + k < n && j + k < n && text[i+k] == text[j+k])
//             k++;

//         lcp_arr[inv_index[i]] = k;

//         if (k > 0)
//             k--;
//     }
// }

// int main() {
//      std::ios_base::sync_with_stdio(false);

//     int t;
//     cin >> t;
//     cin.ignore();

//     string ans = "";
//     while (t--) {
//         string in;
//         cin >> in;
//         in += '$';

//         cin.ignore();

//         // cout << str << endl;

//         build_suffix_array(in);
//         build_lcp_array(in);

//         int n = in.length()-1;
//         n *= (n + 1);
//         n /= 2;

//         for (int i = 1; i < n; i++)
//             n -= lcp_arr[i];

//         ans += to_string(n) + "\n";
//     }

//     cout << ans;

//     return 0;
// }
>>>>>>> 238e238462bc2e3afcec73152a8baa1fdac61909
