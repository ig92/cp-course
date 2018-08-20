#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

typedef struct Query {
    int id;
    int i;
    int j;
} Query;

int n, t;
int table[1000001];
uint64_t answer[200000];
uint64_t power = 0;
long long numbers[200000];

void add(int pos) {
    power -= numbers[pos] * table[numbers[pos]] * table[numbers[pos]];
    table[numbers[pos]]++;
    power += numbers[pos] * table[numbers[pos]] * table[numbers[pos]];
}

void remove(int pos) {
    power -= numbers[pos] * table[numbers[pos]] * table[numbers[pos]];
    table[numbers[pos]]--;
    power += numbers[pos] * table[numbers[pos]] * table[numbers[pos]];
}

bool cmp(Query a, Query b)
{
 	if(a.i/1000!=b.i/1000) return a.i/1000<b.i/1000;
	return (a.j<b.j)^((a.i/1000)%2);
}

int main() {
    std::ios_base::sync_with_stdio(false);

    scanf("%d %d", &n, &t);

    for(int i = 0; i < n; i++)
        scanf("%lld", &numbers[i]);
    
    Query queries[200005];
    for(int i = 0; i < t; i++)
        scanf("%d %d", &queries[i].i, &queries[i].j), queries[i].id = i;

    sort(queries, queries+t, cmp);

    int current_i = 0;
    int current_j = 0;
    add(0);

    for (int q = 0; q < t; ++q) {
        while (current_i < queries[q].i-1)
            remove(current_i++);
        while (current_i > queries[q].i-1)
            add(--current_i);
        while (current_j < queries[q].j-1)
            add(++current_j);
        while (current_j > queries[q].j-1)
            remove(current_j--);
        answer[queries[q].id] = power;
    }
    
    for (int i = 0; i < t; ++i)
        cout << answer[i] << endl;

    return 0;
}