#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool is_magic(string number) {
    if (number.length() == 0)
        return true;
        
    if (number[0] != '1')
        return false;

    if (is_magic(number.substr(1)))
        return true;
    
    if (number[1] != '4')
        return false;
    
    if (is_magic(number.substr(2)))
        return true;
    
    if (number[2] != '4')
        return false;
    
    return is_magic(number.substr(3));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    
    string number;
    getline(cin, number);

    cout << (is_magic(number) ? "YES" : "NO") << endl;

    return 0;
}