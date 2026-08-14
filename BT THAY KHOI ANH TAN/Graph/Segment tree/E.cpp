#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
ll dp[MM],st[MM*4],n,a[MM],p[MM];

void update(ll id,ll l,ll r,ll u,ll cnt)
{
    if(r < u) return;
    if(l == r) {
        st[id] = max(st[id],cnt);
        return;
    }
    ll mid = (l+r)/2;
    if(u <= mid) update(id*2,l,mid,u,cnt);
    else update(id*2+1,mid+1,r,u,cnt);
    st[id] = max(st[id*2],st[id*2+1]);
}

ll get(ll id,ll l,ll r,ll u,ll v)
{
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    ll mid = (l+r)/2;
    return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<ll> v;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i = 1;i <= n;i++) p[i] = lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        dp[i] = get(1,1,n,1,p[i]-1)+1;
        update(1,1,n,p[i],dp[i]);
        dp[i] = max(dp[i],dp[i-1]);
    }
    cout << dp[n];
    return 0;
}