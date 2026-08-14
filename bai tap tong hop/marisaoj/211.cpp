#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 1e5+7;
int n,q,a[MM];

struct Segtree
{
    vector<vector<int>> st;
    vector<int> lazy;
    Segtree(int n): st(n*4+1,vector<int>(4,0)),lazy(n*4+1) {};
    void build(int id,int l,int r)
    {
        if(l == r) {
            for(int i = 0;i < 3;i++) if(a[l] == i) st[id][i] = 1;
            return;
        }
        int mid = (l+r)/2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        for(int i = 0;i < 3;i++) st[id][i] = st[id*2][i] + st[id*2+1][i];
    }

    void fix(int id,int l,int r)
    {
        if(!lazy[id]) return;
        lazy[id] %= 3;

        if(lazy[id] == 1) {
            swap(st[id][0],st[id][2]);
            swap(st[id][1],st[id][2]);
        }
        else if(lazy[id] == 2) {
            swap(st[id][0],st[id][1]);
            swap(st[id][1],st[id][2]);
        }
        
        if(l != r) {
            lazy[id*2] += lazy[id];
            lazy[id*2+1] += lazy[id];
        }
        lazy[id] = 0;
    }
        
    void update(int id,int l,int r,int u,int v)
    {
        fix(id,l,r);
        if(l > v || r < u) return;
        if(u <= l && r <= v) {
            lazy[id]++;
            fix(id,l,r);
            return;
        }
        int mid = (l+r)/2;
        update(id*2,l,mid,u,v);
        update(id*2+1,mid+1,r,u,v);
        for(int i = 0;i < 3;i++) 
            st[id][i] = st[id*2][i] + st[id*2+1][i];
    }

    int get(int id,int l,int r,int u,int v)
    {
        fix(id,l,r);
        if(l > v || r < u) return 0;
        if(u <= l && r <= v) return st[id][0];
        int mid = (l+r)/2;
        return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
    }
};

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        a[i] = a[i] % 3;
    }
    Segtree g(n);
    g.build(1,1,n);
    while(q--) {
        int t,l,r;
        cin >> t >> l >> r;
        if(t == 1) g.update(1,1,n,l,r);
        else cout << g.get(1,1,n,l,r) << '\n';
    }
    return 0;
}