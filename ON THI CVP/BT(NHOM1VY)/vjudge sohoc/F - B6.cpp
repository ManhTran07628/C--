#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;

void solve(ll L,ll R)
{
    ll p[R-L+1];
    for(int i = L;i <= R;i++) {
        p[i-L] = 1;
    }
    for(ll i = 2;i*i <= R;i++)
        for(ll j = max(i*i,(i+L-1)/i*i);j <= R;j+=i)
            p[j-L] = 0;
    if(1 >= L) p[1-L] = 0;
    for(ll i = L;i <= R;i++) {
        if(p[i-L]) cout << i << '\n';
    }
    cout << '\n';
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll m,n;
        cin >> m >> n;
        solve(m,n);
    }
    return 0;
}