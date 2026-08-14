#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
const int maxn = 1000000 + 5; //10^6 + 5
int minPrime[maxn];
ll a[N];
vector<int> factorize(int n) {
    vector<int> res;
    while (n != 1) {
        res.push_back(minPrime[n]);
        n /= minPrime[n];
    }
    return res;
}
int main() {
    ll n;
    cin >> n;
    for (int i = 2; i * i <= n; ++i) {
        if (minPrime[i] == 0) { //if i is prime
            for (int j = i * i; j <= n; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
        }
    }
    //freopen("TAMGIAC.inp","r",stdin);
    //freopen("TAMGIAC.out","w",stdout);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        vector<int> tmp = factorize(a[i]);
        cout << tmp << endl;
    }
    return 0;
}
