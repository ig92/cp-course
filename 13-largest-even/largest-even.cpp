#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

template<typename T>
vector<T> get_input_sequence(size_t n) {
    vector<T> sequence(n);

    for(size_t i = 0; i < n; ++i) 
        cin >> sequence[i];
    return sequence;
}

string largestNumber(string number) {
    vector<int> counters (10);
    int min = 10;
    for (int i = 0; i < number.length(); ++i) {
        int n = number[i] - '0';
        if (n % 2 == 0 && min > n)
            min = n;
        counters[n]++;
    }

    // if no even numbers
    string str = "";
    if (min < 10) {
        counters[min]--;
    }

    for (int i = 9; i > -1; --i) {
        while (counters[i]-- > 0) {
            str += to_string(i);
        }
    }

    if (min < 10) {
        str += to_string(min);
    }
    
    return str;
}

int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    vector<string> number = get_input_sequence<string>(t);

    for (int i = 0; i < t; ++i) {
        cout << largestNumber(number[i]) << endl;
    }
    
    return 0;
}
