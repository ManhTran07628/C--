#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1e9
const int MM = 3e6+7;
int n,a[MM];


namespace sol
{
    int st[MM*4],dp[MM];
    void build(int id,int l,int r)
    {
        if(l == r) {
            if(l != 1) st[id] = 1e9;
            return;
        }
        int mid = (l+r)/2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        st[id] = max(st[id*2],st[id*2+1]);
    }

    void update(int id,int l,int r,int pos,int val)
    {
        if(l > pos || r < pos) return;
        if(l == r) {
            st[id] = min(st[id],val);
            return;
        }
        int mid = (l+r)/2;
        if(pos <= mid) update(id*2,l,mid,pos,val);
        else update(id*2+1,mid+1,r,pos,val);
        st[id] = min(st[id*2],st[id*2+1]);
    }
    
    int get(int id,int l,int r,int u,int v)
    {
        if(l > v || r < u) return oo;
        if(u <= l && r <= v) return st[id];
        int mid = (l+r)/2;
        return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
    }

    void solve()
    {
        build(1,1,n);
        dp[1] = 0;
        update(1,1,n,min(1+a[1],n),1);
        for(int i = 2;i <= n;i++) {
            dp[i] = get(1,1,n,i,n);
            update(1,1,n,min(i+a[i],n),dp[i]+1);
        }
        cout << (dp[n] != oo ? dp[n] : -1);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sol::solve();
    return 0;
}