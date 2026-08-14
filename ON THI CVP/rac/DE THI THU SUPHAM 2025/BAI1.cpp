#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int res = 0;

    for (ll k = 1; k * k <= 1LL * n * n; ++k) {
        ll sq = k * k;
        for (ll d = 1; d * d <= sq; ++d) {
            if (sq % d == 0) {
                ll i = d;
                ll j = sq / d;
                if (i <= n && j <= n) {
                    res++;
                    if (i != j) res++; 
                }
            }
        }
    }

    cout << res << '\n';
    return 0;
}
