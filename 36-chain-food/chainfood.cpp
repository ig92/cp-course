#include <iostream>
#define MAX 50001

using namespace std;

int P[MAX], S[MAX];

int find(int x) {
	if (x == P[x])
        return x;
	
    int tmp = P[x];
	P[x] = find(P[x]);
	S[x] += S[tmp];
	
    return P[x];
}

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
        int n, k;
        cin >> n >> k;
		
        for (int i = 1; i <= n; i++) {
			P[i] = i;
			S[i] = 0;
		}

		int counter = 0;
		while (k-- > 0) {
            int type, x, y;
            cin >> type >> x >> y;

			if (x > n || y > n) {
                counter++;
                continue;
            }
			
            int rx = find(x);
			int ry = find(y);
			
            type--;
			if (rx == ry) {
				int diff = (S[x] - S[y]) % 3;
                if (diff < 0)
                    diff += 3;
				if (diff != type) 
                    counter++;
			}
			else {
				P[rx] = ry;
				int i = (S[x] - S[y] - type) % 3;
				S[rx] = (i < 0) ? -i : -i + 3;
			}
		}
		
        cout << counter << endl;
	}
	return 0;
}