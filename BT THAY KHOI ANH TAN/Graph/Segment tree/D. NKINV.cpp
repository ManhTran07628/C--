#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
ll n,a[MM],ans = 0,st[MM*4],p[MM];
void update(ll id,ll l,ll r,ll v)
{
    if(l > v || r < v) return;
    if(l == r) {
        st[id]++;
        return;
    }
    ll mid = (l+r)/2;
    update(id*2,l,mid,v);
    update(id*2+1,mid+1,r,v);
    st[id] = st[id*2] + st[id*2+1];
}

ll get(ll id,ll l,ll r,ll v)
{
    if(l > v || r < 1) return 0;
    if(r <= v) return st[id];
    ll mid = (l+r)/2;
    return get(id*2,l,mid,v) + get(id*2+1,mid+1,r,v);
}



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> v;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i = 1;i <= n;i++) {
        p[i] = lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
    }
    ll ans = 0;
    for(int i = n;i >= 1;i--) {
        ans += get(1,1,n,p[i]-1);
        update(1,1,n,p[i]);
    }
    cout << ans;
    return 0;
}