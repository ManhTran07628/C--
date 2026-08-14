#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// Hàm kiểm tra số chính phương
bool isPerfectSquare(unsigned long long x) {
    unsigned long long s = (unsigned long long)sqrt(x);
    return s * s == x;
}

bool canMultiply(unsigned long long current, unsigned int x) {
    // Kiểm tra tràn số trước khi nhân
    return current <= numeric_limits<unsigned long long>::max() / x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    unsigned long long current = 1;
    unsigned int x;

    for (int i = 0; i < N; ++i) {
        cin >> x;

        if (canMultiply(current, x)) {
            current *= x;

            if (isPerfectSquare(current)) {
                cout << "DA" << endl;
            } else {
                cout << "NE" << endl;
            }
        } else {
            cout << "NE" << endl;
        }
    }

    return 0;
}
