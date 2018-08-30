#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    
    string hello = "hello";
    
    string s;
    getline(cin, s);

    int i = 0;
    int j = 0;

    while (i < s.length() && j < hello.length())
        if (s[i++] == hello[j])
            j++;

    cout << (j == hello.length() ? "YES" : "NO") << endl;

    return 0;
}