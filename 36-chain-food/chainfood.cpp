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

int mod3(int x) {
	int remainder = x % 3;
	if (remainder < 0)
		remainder += 3;
	return remainder;
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
				if (mod3(type + S[y] - S[x]) != 0) 
                    counter++;
			}
			else {
				// otherwise, whatever is the type
				// we need to connect the two sets
				// with some relation
				P[rx] = ry;
				int i = mod3(type + S[y] - S[x]);
				if (i == 0)
					i = 3;
				S[rx] = i;
			}
		}
		
        cout << counter << endl;
	}
	return 0;
}