#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 3e4+7;
int n,a[MM],q;
vector<int> st[MM*4];
void readinput()
{
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    cin >> q;
}

void build(int id,int l,int r)
{
    if(l == r) {
        st[id].push_back(a[l]);
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    for(auto v:st[id*2]) st[id].push_back(v);
    for(auto v:st[id*2+1]) st[id].push_back(v);
    sort(st[id].begin(),st[id].end());
}

int get(int id,int l,int r,int u,int v,int k)
{
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) {
        int pos = upper_bound(st[id].begin(),st[id].end(),k) - st[id].begin();
        return st[id].size()-pos;
    }
    int mid = (l+r)/2;
    return get(id*2,l,mid,u,v,k) + get(id*2+1,mid+1,r,u,v,k);
}

void solve()
{
    build(1,1,n);
    while(q--) {
        int i,j,k;
        cin >> i >> j >> k;
        cout << get(1,1,n,i,j,k) << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readinput();
    solve();
    return 0;
}