#include <iostream>
#include <algorithm>

using namespace std;

class BigInteger {
private:
	string integer;
public:
	BigInteger(string integer);
	void setInteger(unsigned int integer);
	void setInteger(string integer);
	unsigned int getIntValue() const;
	string toString() const;
	BigInteger addInteger(const BigInteger& integer_to_add) const;
	BigInteger addInteger(const string& integer_to_add) const;
	static size_t getTrimIndex(const string& integer);
	BigInteger operator+(const BigInteger& integer) const;
};


BigInteger::BigInteger(string integer) {
	for (int i = 0; i < (int)integer.size() && integer[i] >= '0' && integer[i] <= '9'; i++) {
		this->integer += integer[i];
	}

	if (this->integer.size() == 0) {
		this->integer = "0";
	} else {
		this->integer = integer.substr(getTrimIndex(integer));
	}
}

void BigInteger::setInteger(string integer) {
	this->integer = integer;
}

unsigned int BigInteger::getIntValue() const {
	unsigned int ret = 0;
	unsigned int biggest = 0xFFFFFFFF;
	for (int i = 0; i < (int)integer.size(); i++) {
		int unit = integer[i] - '0';
		if (ret > (biggest - unit) / 10.0) return 0;
		ret = ret * 10 + unit;
	}
	return ret;
}

string BigInteger::toString() const {
	return integer;
}

BigInteger BigInteger::addInteger(const BigInteger& integer_to_add) const {
	int a_n = max((int)(integer_to_add.toString().size() - toString().size()), 0);
	int b_n = max((int)(toString().size() - integer_to_add.toString().size()), 0);
	string a = string(a_n, '0') + toString();
	string b = string(b_n, '0') + integer_to_add.toString();

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	string result; int carry = 0;

	for (int i = 0; i < (int)a.size(); i++) {
	   int sum = (a[i] - '0') + (b[i] - '0') + carry;
	   result += ((char)(sum % 10 + '0'));
	   carry = sum / 10;
	}

	if (carry != 0) result += ((char)(carry + '0'));

	reverse(result.begin(), result.end());

	return BigInteger(result.substr(getTrimIndex(result)));
}

BigInteger BigInteger::addInteger(const string& integer_to_add) const {
	return addInteger(BigInteger(integer_to_add));
}

size_t BigInteger::getTrimIndex(const string& integer) {
	size_t index = 0;
	while (integer[index] == '0' && index < integer.size() - 1) index++;
	return index;
}

BigInteger BigInteger::operator+(const BigInteger& integer) const {
	return addInteger(integer);
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    BigInteger fibX ("2");
    BigInteger fibY ("3");

    if (n <= 2) {
        cout << n+1 << endl;
        return 0;
    }

    for (int i = 2; i < n; ++i) {
        BigInteger tmp = fibX;
        fibX = fibY;
        fibY = fibY + tmp;
    }

    cout << fibY.toString() << endl;

    return 0;
}

