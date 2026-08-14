#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
ll n,a[MM],st[MM*4],ps[MM],pos[MM],ans = 0;
vector<ll> v;

void update(ll id,ll l,ll r,ll u,ll v)
{
    if(l > v || r < u) return;
    if(l == r) {
        st[id]++;
        return;
    }
    ll mid = (l+r)/2;
    update(id*2,l,mid,u,v);
    update(id*2+1,mid+1,r,u,v);
    st[id] = st[id*2] + st[id*2+1];
}

ll get(ll id,ll l,ll r,ll u,ll v)
{
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    ll mid = (l+r)/2;
    return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        ps[i] = ps[i-1] + a[i];
        v.push_back(ps[i]);
    }
    // nen so
    v.push_back(0);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i = 0;i <= n;i++) {
        pos[i] = lower_bound(v.begin(),v.end(),ps[i]) - v.begin()+1;
    }
    for(int i = 0;i <= n;i++) {
        ans += get(1,1,n,1,pos[i]); // dem so luong ps[i] - ps[j] >= 0
        update(1,1,n,pos[i],pos[i]); // da gap ps[i]
    }
    cout << ans;
    return 0;
}