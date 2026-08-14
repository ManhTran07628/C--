#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1e18
const int MM = 1e6+7;
int n,q,ans[MM];
pair<int,int> a[MM];

struct dl{
    int l,r,k,id;
};
dl query[MM];

struct Segtree{
    vector<int> st;
    Segtree(int n) : st(n*4+1) {};

    void update(int id,int l,int r,int pos)
    {
        if(l > pos || r < pos) return;
        if(l == r) {
            st[id] = 1;
            return;
        }
        int mid = (l+r)/2;
        update(id*2,l,mid,pos);
        update(id*2+1,mid+1,r,pos);
        st[id] = st[id*2] + st[id*2+1];
    }

    int get(int id,int l,int r,int u,int v)
    {
        if(l > v || r < u) return 0;
        if(u <= l && r <= v) return st[id];
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
        cin >> a[i].first;
        a[i].second = i;
    }
    for(int i = 1;i <= q;i++) {
        cin >> query[i].l >> query[i].r >> query[i].k;
        query[i].id = i;
    }
    Segtree g(n);
    sort(a+1,a+n+1,greater<pair<int,int>>());
    sort(query+1,query+q+1, [] (dl &a,dl &b) {
        return a.k > b.k;
    });
    for(int j = 1,i = 1;j <= q;j++) {
        int l = query[j].l, r = query[j].r, k = query[j].k, id = query[j].id;
        while(i <= n && a[i].first > k) {
            g.update(1,1,n,a[i].second);
            i++;
        }
        ans[id] = g.get(1,1,n,l,r);
    }
    for(int i = 1;i <= q;i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}