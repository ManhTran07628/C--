#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
int n,a[MM];
ll p,st[MM * 4],ps[MM];

void update(int id,int l,int r,int pos,ll val)
{
    if(l > pos || r < pos) return;
    if(l == r) {
        st[id] = min(st[id],val);
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id] = min(st[id*2],st[id*2+1]);
}

ll get(int id,int l,int r,ll val)
{
    if(st[id] > val) return oo;
    if(l == r) return l;
    int mid = (l + r) / 2;
    ll memo = oo;
    if(st[id*2] <= val) return get(id*2,l,mid,val);
    else return get(id*2+1,mid+1,r,val);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> p;
    for(int i = 1;i <= n;i++) cin >> a[i];
    ll res = -1;
    for(int i = 1;i < MM * 4;i++) st[i] = oo;
    for(int i = 1;i <= n;i++) {
        ps[i] = ps[i-1] + a[i];
        ll pos = get(1,1,n,ps[i] - p);
        res = max(res,i - pos);
        update(1,1,n,i,ps[i]);
    }
    cout << res;
    return 0;
}