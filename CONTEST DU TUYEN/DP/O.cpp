#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 2e5 + 7;
int n,h[MM + 7],a[MM + 7];
ll st[MM * 4 + 7];

void update(int id,int l,int r,int pos,ll val)
{
    if(l > pos || r < pos) return;
    if(l == r) {
        st[id] = max(st[id],val);
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id] = max(st[id*2],st[id*2+1]);
}

ll get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return max(get(id*2,l,mid,u,v), get(id*2+1,mid+1,r,u,v));
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> h[i];
    for(int i = 1;i <= n;i++) cin >> a[i];

    ll res = 0;
    for(int i = 1;i <= n;i++) {
        ll val = get(1,1,MM,1,h[i] - 1);
        res = max(res,val + a[i]);
        update(1,1,MM,h[i],val + a[i]);
    }
    cout << res;
    return 0;
}