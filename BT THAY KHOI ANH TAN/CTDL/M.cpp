#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e3+7;
int n,m,q,k;
int a[MM][MM];
set<int> qr;
unordered_map<int,int> ans;
map<int, vector< pair<int,int> > > adj;
void init()
{
    cin >> n >> m >> q >> k;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
            a[i][j] %= k;
            adj[ a[i][j] ].push_back({i , j});
            qr.insert(a[i][j]);
        }
    }

}

int st[MM*4];

void update(int id,int l,int r,int pos,int val)
{
    if(l > pos || r < pos) return;
    if(l == r) {
        st[id] = max(st[id],val);
        return;
    }
    int mid = (l+r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id] = max(st[id*2],st[id*2+1]);
}

int get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    int mid = (l+r)/2;
    return max(get(id*2,l,mid,u,v), get(id*2+1,mid+1,r,u,v));
}



void solve()
{
    for(auto i:qr) {
        // cout << i << '\n';
        // for(auto x:adj[i]) cout << x.fi << ' ' << x.se << '\n';
        // cout << '\n';
        int max_w = 1;
        memset(st,0,sizeof(st));
        for(auto x:adj[i]) {
            int cur_w = get(1,1,m,1,x.se);
            update(1,1,m,x.se,cur_w+1);
            max_w = max(max_w,cur_w+1);
        }
        ans[i] = max_w;


    }


    while(q--) {
        int x;
        cin >> x;
        cout << ans[x] << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    solve();
    return 0;
}
