#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll ans = 0;
    for(int i = 1;i <= sqrt(n);i++) {
        if(n % i == 0) {
            ans += i;
            if(n / i != i) ans += n/i;
        }
    }
    cout << ans;
    return 0;
}