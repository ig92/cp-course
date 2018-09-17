#include <iostream>
#include <deque>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    
    string sequence;
    getline(cin, sequence);

    deque<char> letters;
    for (int i = 0; i < sequence.length(); ++i) {
        while (!letters.empty() && letters.front() < sequence[i])
            letters.pop_front();
        letters.push_front(sequence[i]);
    }

    while (!letters.empty()) {
        cout << letters.back();
        letters.pop_back();
    }
    cout << endl;

    return 0;
}