#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 2e5+7;
int n,q,t[MM];
ll cnt[MM * 4],b[MM * 4],st[MM * 4];


void build(int id,int l,int r)
{
    if(l == r) {
        st[id] = t[l];
        cnt[id] = 0;
        b[id] = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = st[id*2] + st[id*2+1];
}

void fix(int id,ll l,ll r)
{
    if(cnt[id] == 0 && b[id] == 0) return;
    ll p2 = ( l * (r - l + 1) + (r - l) * (r - l + 1) / 2 ) * cnt[id];
    ll p3 = (r - l + 1) * b[id];
    st[id] += p2 + p3;
    if(l != r) {
        cnt[id*2] += cnt[id];
        cnt[id*2+1] += cnt[id];
        b[id*2] += b[id];
        b[id*2+1] += b[id];
    }
    cnt[id] = 0;
    b[id] = 0;
}

void update(int id,int l,int r,int u,int v,ll val1,ll val2)
{
    fix(id,l,r);
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        b[id] += val1;
        cnt[id] += val2;
        fix(id,l,r);
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,u,v,val1,val2);
    update(id*2+1,mid+1,r,u,v,val1,val2);
    st[id] = st[id*2] + st[id*2+1];
}

ll get(int id,int l,int r,int u,int v)
{
    fix(id,l,r);
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> t[i];
    build(1,1,n);
    while(q--) {
        int type,a,b;
        cin >> type >> a >> b;
        if(type == 1) {
            update(1,1,n,a,b,-(a - 1),1);
        }
        else cout << get(1,1,n,a,b) << '\n';
    }
    return 0;
}