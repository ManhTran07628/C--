#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6;
int n,q,a[MM + 7];
map<int,int> mp,firstpos;
int st[MM * 4],ans[MM + 7];
vector<pii> qr[MM + 7];

void update(int id,int l,int r,int pos,int val)
{
    if(l > pos || r < pos) return;
    if(l == r) {
        st[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id] = st[id*2] + st[id*2+1];
}

int get(int id,int l,int r,int u,int v)
{
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
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= q;i++) {
        int u,v; cin >> u >> v;
        qr[v].push_back({u,i});
    }
    for(int i = 1;i <= n;i++) {
        if(!firstpos[ a[i] ]) {
            update(1,1,n,i,1);
            firstpos[ a[i] ] = i;
        }
        else {
            update(1,1,n,firstpos[ a[i] ],0);
            firstpos[ a[i] ] = i;
            update(1,1,n,firstpos[ a[i] ],1);
        }
        

        for(auto U: qr[i]) {
            int j = U.fi , id = U.se;
            int query = get(1,1,n,j,i);
            // ans[id] = query;
            if(i - j + 1 != query) ans[id] = 1;
        }
    }
    for(int i = 1;i <= q;i++)
        cout << ans[i];
    return 0;
}