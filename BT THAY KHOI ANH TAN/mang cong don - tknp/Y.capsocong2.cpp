#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll a[MAXN],d[MAXN],t[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int q;
    cin >> q;
    while(q--) {
        ll l,r,x;
        cin >> l >> r >> x;
        d[l] += 1;
        d[r+1] -= 1;
        t[l] += (x-l);
        t[r+1] -= (x-l);
    }
    for(int i = 1;i <= n;i++) {
        d[i] += d[i-1];
        t[i] += t[i-1];
        cout << a[i]+d[i]*i+t[i] << ' ';
    }
    return 0;
}