#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int q;
    cin >> q;
    while(q--) {
        ll x;
        cin >> x;
        ll p = upper_bound(a+1,a+n+1,x)-a-1;
        if(p == 0) cout << -1 << '\n';
        else cout << a[p] << '\n';
    }
    return 0;
}