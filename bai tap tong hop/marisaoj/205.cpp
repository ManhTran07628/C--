#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
ll n,q,dp[MM],st[MM*4],lazy[MM*4];
vector<pair<int,int>> adj[MM];
void build(ll id,ll l,ll r)
{
    st[id] = lazy[id] = oo;
    if(l == r) return;
    ll mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
}

void fix(ll id,ll l,ll r)
{
    if(lazy[id] == oo) return;
    st[id] = min(st[id],lazy[id]);
    lazy[id*2] = min(lazy[id*2],lazy[id]);
    lazy[id*2+1] = min(lazy[id*2+1],lazy[id]);
    lazy[id] = oo;
}

void update(ll id,ll l,ll r,ll u,ll v,ll val)
{
    fix(id,l,r);
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        lazy[id] = val;
        fix(id,l,r);
        return;
    }
    ll mid = (l+r)/2;
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    st[id] = min(st[id*2],st[id*2+1]);
}

ll get(ll id,ll l,ll r,ll u)
{
    fix(id,l,r);
    if(!u) return 0;
    if(l == r) return st[id];
    ll mid = (l+r)/2;
    if(mid < u) return get(id*2+1,mid+1,r,u);
    return get(id*2,l,mid,u);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= q;i++) {
        ll l,r,c;
        cin >> l >> r >> c;
        adj[r].push_back({l,c});
    }
    for(int i = 1;i <= n;i++) {
        sort(adj[i].begin(),adj[i].end());
    }
    build(1,1,n);
    fill(dp+1,dp+n+1,oo);
    for(ll r = 1;r <= n;r++) {
        for(auto d:adj[r]) {
            ll l = d.fi, c = d.se;
            dp[r] = min(dp[r],get(1,1,n,l-1)+c);
            update(1,1,n,l,r,dp[r]);
        }
    }
    dp[n] = get(1,1,n,n);
    cout << (dp[n] != oo? dp[n] : -1);
    return 0;
}