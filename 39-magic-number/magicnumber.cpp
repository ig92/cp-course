#include <iostream>
#include <vector>

using namespace std;

string is_magic(string number) {
    if (number.length() == 0)
        return "YES";
    
    int n = number.length();

    if (number[n-1] == '1')
        return is_magic(number.substr(0, n-1));
    
    if (number[n-2] == '1' && number[n-1] == '4')
        return is_magic(number.substr(0, n-2));
    
    if (number[n-3] == '1' && number[n-2] == '4' && number[n-1] == '4')
        return is_magic(number.substr(0, n-3));

    return "NO";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    
    string number;
    getline(cin, number);

    cout << is_magic(number) << endl;

    return 0;
}