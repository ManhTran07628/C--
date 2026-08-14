#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 2e5 + 7;
const int LOG = 18;
int n,q;
ll k,a[MM],lastpos[MM],res[MM];
vector<pii> adj[MM];

ll st[MM * 4];

void update(int id,int l,int r,int pos,ll val)
{
    if(l > pos || r < pos) return;
    if(l == r) {
        st[id] = min(st[id],val);
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id] = min(st[id*2],st[id*2+1]);
}

ll get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return oo;
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return min(get(id*2,l,mid,u,v), get(id*2+1,mid+1,r,u,v));
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
    cin >> n >> q >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }

    for(int i = 1;i <= n;i++) {
        int pos = upper_bound(a+1,a+n+1,a[i] - k) - a - 1;
        if(a[i] - a[pos] < k) {
            lastpos[i] = -1;
            continue;
        }
        lastpos[i] = pos + 1;
    }

    for(int i = 0;i < MM * 4;i++) st[i] = oo;

    for(int i = 1;i <= q;i++) {
        int l,r; cin >> l >> r;
        adj[r].push_back({l,i});
    }   

    for(int r = 1;r <= n;r++) {
        if(lastpos[r] != -1) update(1,1,n,lastpos[r],r - lastpos[r] + 1);
        for(auto qr:adj[r]) {
            int l = qr.fi, id = qr.se;
            res[id] = get(1,1,n,l,r);
        }
    }

    for(int i = 1;i <= q;i++) cout << (res[i] == oo ? -1 : res[i]) << '\n';
    return 0;
}