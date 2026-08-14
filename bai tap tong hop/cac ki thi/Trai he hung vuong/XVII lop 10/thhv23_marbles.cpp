#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 2e5 + 7;
ll n,a[MM];
ll res = 0;

pii st[MM * 4];

pii Merge(pii a,pii b)
{
    int sum = a.fi + b.fi;
    return {sum,0};
}

void build(int id,int l,int r)
{
    if(l == r) {
        st[id] = {1,l};
        return;
    }
    int mid = (l + r) / 2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = Merge(st[id*2],st[id*2+1]);
}

void update(int id,int l,int r,int pos,int val)
{
    if(l > pos || r < pos) return;
    if(l == r) {
        st[id] = {0,val};
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id] = Merge(st[id*2],st[id*2+1]);
}

pii get(int id,int l,int r,int x)
{
    if(st[id].fi < x) return {0,-1};
    if(l == r) return st[id];
    int mid = (l + r) / 2;
    if(st[id*2].fi >= x) return get(id*2,l,mid,x);
    return get(id*2+1,mid+1,r,x - st[id*2].fi);
}



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    build(1,1,n);
    for(int i = 1;i <= n-2;i++) {
        int b; cin >> b;
        int x1 = get(1,1,n,b - 1).se, x2 = get(1,1,n,b).se, x3 = get(1,1,n,b + 1).se;
        res += a[x2] * (a[x1] + a[x3]);
        update(1,1,n,x2,0);
    }
    cout << res;
    return 0;
}