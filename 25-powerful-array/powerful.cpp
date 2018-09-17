#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct Query {
    int id;
    int i;
    int j;
};

int table[1000001];
uint64_t answer[200000];
uint64_t power = 0;
long long numbers[200000];

int main() {
    std::ios_base::sync_with_stdio(false);

    int n, t;
    scanf("%I64d %I64d", &n, &t);

    for(int i = 0; i < n; i++)
        scanf("%I64d", &numbers[i]);
    
    Query queries[t];
    for(int i = 0; i < t; i++) {
        queries[i].id = i;
        scanf("%I64d %I64d", &queries[i].i, &queries[i].j);
    }

    int p = sqrt(n);
    sort(queries, queries+t, [p](Query a, Query b) {
        if (a.i / p == b.i / p) 
            return a.j < b.j;
        return a.i < b.i;
    });

    int current_i = 0;
    int current_j = 0;

    int v = table[numbers[0]];
    power -= numbers[0] * v * v;
    table[numbers[0]]++;
    v++;
    power += numbers[0] * v * v;
    for (int q = 0; q < t; ++q) {
        while (current_i < queries[q].i-1) {
            v = table[numbers[current_i]];
            power -= numbers[current_i] * v * v;
            table[numbers[current_i]]--;
            v--;
            power += numbers[current_i] * v * v;
            current_i++;
        }
        while (current_i > queries[q].i-1) {
            current_i--;
            v = table[numbers[current_i]];
            power -= numbers[current_i] * v * v;
            table[numbers[current_i]]++;
            v++;
            power += numbers[current_i] * v * v;
        }
        while (current_j < queries[q].j-1){
            current_j++;
            v = table[numbers[current_j]];
            power -= numbers[current_j] * v * v;
            table[numbers[current_j]]++;
            v++;
            power += numbers[current_j] * v * v;
        }
        while (current_j > queries[q].j-1) {
            v = table[numbers[current_j]];
            power -= numbers[current_j] * v * v;
            table[numbers[current_j]]--;
            v--;
            power += numbers[current_j] * v * v;
            current_j--;
        }
        answer[queries[q].id] = power;
    }
    
    for (int i = 0; i < t; ++i)
        printf("%I64d\n", answer[i]);

    return 0;
}