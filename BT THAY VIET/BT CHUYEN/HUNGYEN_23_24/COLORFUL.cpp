#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int n,q,c[MM];

void ReadInput()
{
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> c[i];
}

namespace subtask1
{
    map<int,int> mp;
    void solve()
    {
        while(q--) {
            int t,u,v;
            cin >> t >> u >> v;
            if(t == 1) {
                swap(c[u],c[v]);
            }
            else {
                for(int i = u;i <= v;i++) mp[c[i]]++;
                cout << mp.size() << '\n';
                mp.clear();
            }
        } 
    }
}

namespace subtask3
{
    map<int,int> st[MM*4];
    void build(int id,int l,int r)
    {
        if(l == r) {
            st[id][c[l]]++;
            return;
        }
        int mid = (l+r)/2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        for(auto v:st[id*2]) st[id][v.fi]++;
        for(auto v:st[id*2+1]) st[id][v.fi]++;
    }

    map<int,int> get(int id,int l,int r,int u,int v)
    {
        if(l > v || r < u) return {};
        if(u <= l && r <= v) return st[id];
        int mid = (l+r)/2;
        auto L = get(id*2,l,mid,u,v);
        auto R = get(id*2+1,mid+1,r,u,v);
        for(auto v:R) {
            L[v.fi]++;
        }
        return L;
    }

    void solve()
    {
        build(1,1,n);
        while(q--)
        {
            int t,u,v;
            cin >> t >> u >> v;
            map<int,int> mp = get(1,1,n,u,v);
            cout << mp.size() << '\n';
        }
        
    }

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ReadInput();
    if(n <= 1000 && q <= 1000) subtask1::solve();
    else subtask3::solve();
    return 0;
}