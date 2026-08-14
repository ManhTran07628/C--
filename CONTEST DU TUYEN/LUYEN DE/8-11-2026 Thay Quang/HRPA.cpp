#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    vector<long long> fib = {1, 2};

    while (fib.back() <= N) {
        long long x = fib[fib.size() - 1] + fib[fib.size() - 2];
        if (x > N) break;
        fib.push_back(x);
    }

    for (int i = (int)fib.size() - 1; i >= 0; --i) {
        if (fib[i] <= N) {
            N -= fib[i];

            if (N == 0) {
                cout << fib[i] << '\n';
                return 0;
            }
        }
    }
}
