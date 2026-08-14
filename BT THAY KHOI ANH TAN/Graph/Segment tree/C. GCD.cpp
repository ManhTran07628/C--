#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 5e5+7;
ll n,k,a[MM],st[MM*4];

void build(ll id,ll l,ll r)
{
    if(l == r) {
        st[id] = a[l];
        return;
    }
    ll mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = __gcd(st[id*2],st[id*2+1]);
}

ll get(ll id,ll l,ll r,ll u,ll v)
{
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    ll mid = (l+r)/2;
    ll get1 = get(id*2,l,mid,u,v);
    ll get2 = get(id*2+1,mid+1,r,u,v);
    
    return __gcd(get1,get2);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    build(1,1,n);
    ll ans = 1;
    for(int i = 1;i <= n-k;i++) {
        ans = max(ans,get(1,1,n,i,i+k-1));
    }
    cout << ans;
    return 0;
}