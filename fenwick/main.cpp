#include <iostream>
#include "bit.h"

int main() {
    int i;
    cin >> i;
    BIT bit (10);
    bit.add(1,1);
    bit.add(5,2);
    bit.add(10,1);
    cout << bit.sum(i) << endl;
}