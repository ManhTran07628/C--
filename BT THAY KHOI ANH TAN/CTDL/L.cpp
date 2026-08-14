#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int n,q,ans[MM];
pair<int,int> coord[MM];
struct dl{int u,v,id;} qr[MM];

void init()
{
    cin >> n;
    for(int i = 1;i <= n;i++) {
        int x,y,u,v;
        cin >> x >> y >> u >> v;
        coord[i] = {u,v};
    }
    cin >> q;
    for(int i = 1;i <= q;i++) {
        int u,v;
        cin >> u >> v;
        qr[i] = {u,v,i};
    }
}

int st[MM*4];

void update(int id,int l,int r,int pos)
{
    if(l > pos || r < pos) return;
    if(l == r) {
        st[id]++;
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


void solve()
{
    
    vector<int> v;
    
    for(int i = 1;i <= n;i++) v.push_back(coord[i].se);
    for(int i = 1;i <= q;i++) v.push_back(qr[i].v);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    int m = v.size();
    for(int i = 1;i <= n;i++) 
        coord[i].se = lower_bound(v.begin(),v.end(),coord[i].se) - v.begin()+1;
    
    for(int i = 1;i <= q;i++) 
        qr[i].v = lower_bound(v.begin(),v.end(),qr[i].v) - v.begin()+1;
    
    sort(coord+1,coord+n+1);
    sort(qr+1,qr+q+1, [] (dl &a,dl &b){
        if(a.u != b.u) return a.u < b.u;
        return a.v < b.v;
    });

    // for(int i = 1;i <= n;i++) cout << coord[i].fi << ' ' << coord[i].se << '\n';
    // cout << '\n';
    // for(int i = 1;i <= q;i++) cout << qr[i].u << ' ' << qr[i].v << '\n';

    for(int i = 1,j = 1;j <= q;j++) {
        while(i <= n && coord[i].fi <= qr[j].u) {
            update(1,1,m,coord[i].se);
            i++;
        }
        ans[qr[j].id] = get(1,1,m,1,qr[j].v);
        // cout << qr[j].u << ' ' << qr[j].v << ' ' << qr[j].id << '\n';
    }

    for(int i = 1;i <= q;i++) cout << ans[i] << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    solve();
    return 0;
}