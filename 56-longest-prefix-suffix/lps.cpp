#include <iostream>
#include <string>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string str;
        getline(cin, str);

        int pp [str.length()];
        pp[0] = 0;
        int i = 1, j = 0;
        while (i < str.length())
            if (str[j] == str[i])
                pp[i++] = ++j;
            else if (j == 0)
                pp[i++] = 0;
            else 
                j = pp[j-1];

        cout << pp[str.length()-1] << endl;       
    }

    return 0;
}