#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
ll n,st[MM*4],dp[MM];
vector<pair<int,int>> vt;

void update(ll id,ll l,ll r,ll v,ll val)
{
    if(l > v || r < v) return;
    if(l == r) {
        st[id] = max(st[id],val);
        return;
    }
    ll mid = (l+r)/2;
    update(id*2,l,mid,v,val);
    update(id*2+1,mid+1,r,v,val);
    st[id] = max(st[id*2],st[id*2+1]);
}

ll get(ll id,ll l,ll r,ll u,ll v)
{
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    int mid = (l+r)/2;
    return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        ll l,r;
        cin >> l >> r;
        vt.push_back({l,r});
    }
    sort(vt.begin(),vt.end(),[] (auto &a,auto &b){
        return a.se < b.se;
    });
    for(int i = 0;i < n;i++) {
        int l = vt[i].fi,r = vt[i].se;
        dp[i] = get(1,1,MM-7,1,l-1);
        update(1,1,MM-7,r,dp[i]+r-l+1);
        ans = max(ans,dp[i]+r-l+1);
    }
    cout << ans;
    return 0;
}