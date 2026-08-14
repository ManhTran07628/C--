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
    int c;
    cin >> c;
    while(c--) {
        ll n;
        bool ok = 0;
        cin >> n;
        for(ll i = 1;i*i <= n;i++) {
            ll x = sqrt(n-i*i);
            if(x*x == (n-i*i)) {
                ok = 1;
                break;
            }
        }
        if(ok) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}