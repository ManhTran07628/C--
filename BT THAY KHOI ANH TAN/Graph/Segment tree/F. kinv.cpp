#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
const int MOD = 1e9;
ll n,k,a[MM],dp[MM][11],st[MM*4];

void update(ll id,ll l,ll r,ll u,ll v,ll val)
{
    if(l > v || r < u) return;
    if(l == r) {
        st[id] = val;
        st[id] %= MOD;
        return;
    }
    ll mid = (l+r)/2;
    if(v <= mid) update(id*2,l,mid,u,v,val);
    else update(id*2+1,mid+1,r,u,v,val);
    st[id] = (st[id*2] + st[id*2+1]) % MOD;
}

ll get(ll id,ll l,ll r,ll u,ll v)
{
    if(u > v) return 0; // a[i] = n
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    ll mid = (l+r)/2;
    return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++) dp[i][1] = 1;

    for(int len = 2;len <= k;len++) {
        memset(st,0,sizeof(st));
        for(int i = 1;i <= n;i++) {
            dp[i][len] = get(1,1,n,a[i]+1,n);
            update(1,1,n,a[i],a[i],dp[i][len-1]);
        }
    }
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        ans = (ans + dp[i][k]) % MOD;
    }
    cout << ans;
    return 0;
}