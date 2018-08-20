#include <vector>
#include <iostream>

using namespace std;
#define LSB(i) ((i) & -(i))

class BIT {
public:
    BIT(uint64_t _size) {
        if (_size < 1)
            _size = 10;
        size = _size + 1;
        A = new int64_t[size];
    }

    ~BIT() {
        delete [] A;
    }

    void add(uint64_t i, int64_t qty) {
        if (i < 1 || i > size)
            return;
        while (i < size) {
            A[i] += qty;
            i += LSB(i);
        }
    }

    int64_t sum(uint64_t i) {
        if (i < 1 || i > size)
            return 0;
        int64_t sum = 0;
        while (i > 0) {
            sum += A[i];
            i -= LSB(i);
        }
        return sum;
    }
private:
    uint64_t size;
    int64_t * A;
};