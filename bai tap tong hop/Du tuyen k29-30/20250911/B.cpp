#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 2e5+7;
ll a[MM],n,q;
ll stp[MM*4],stm[MM*4],lazyp[MM],lazym[MM];

void readinput()
{
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
}

void fixp(int id,int l,int r)
{
    if(!lazyp[id]) return;
    stp[id] += (r-l+1) * lazyp[id];
    if(l != r) {
        lazyp[id*2] += lazyp[id];
        lazyp[id*2+1] += lazyp[id];
    }
    lazyp[id] = 0;
}

void fixm(int id,int l,int r)
{
    if(!lazym[id]) return;
    stm[id] += (r-l+1) * lazym[id];
    if(l != r) {
        lazym[id*2] += lazym[id];
        lazym[id*2+1] += lazym[id];
    }
    lazym[id] = 0;
}

void update(int id,int l,int r,int u,int v,ll v1,ll v2)
{
    fixp(id,l,r);
    fixm(id,l,r);
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        lazyp[id] += v1;
        lazyp[id] += v2;
        fixp(id,l,r);
        fixm(id,l,r);
    }
    int mid = (l+r)/2;
    update(id*2,l,mid,u,v,v1,v2);
    update(id*2+1,mid+1,r,u,v,v1,v2);
    stp[id] = stp[id*2] + stp[id*2+1];
    stm[id] = stm[id*2] + stm[id*2+1];
}

pair<ll,ll> get(int id,int l,int r,int u,int v)
{
    fixp(id,l,r);
    fixm(id,l,r);
    if(l > v || r < u) return {0,0};
    if(u <= l && r <= v) return {stp[id],stm[id]};
    int mid = (l+r)/2;
    auto left = get(id*2,l,mid,u,v);
    auto right = get(id*2+1,mid+1,r,u,v);
    return ({left.fi+right.fi,left.se+right.se});
}

void solve()
{
    while(q--) {
        ll t,a,b;
        cin >> t >> a >> b;
        if(t == 1) {
            update(1,1,n,a,b,1,a-1);
        }
        else 
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}