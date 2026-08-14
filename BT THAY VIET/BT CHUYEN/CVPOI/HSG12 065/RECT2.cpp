#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
const int MM = 1e3 + 7;
int n,vis[MM],sz = 0;
struct hcn
{
    int mi[4] = {},ma[4] = {};

    void Make()
    {
        for(int i = 0;i < 4;i++) mi[i] = oo;
        for(int i = 0;i < 4;i++) ma[i] = -oo;
    }

} sq[MM];

int iscross(int x,int y,int u,int v)
{
    if(x > v || y < u) return 0;
    return 1;
}

vector<int> adj[MM];

void dfs(int u)
{
    sz++;
    vis[u] = 1;
    for(auto v:adj[u]) {
        if(vis[v]) continue;
        vis[u] = 1;
        dfs(v);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "rect2"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) sq[i].Make();


    for(int i = 1;i <= n;i++) {
        for(int j = 0;j < 4;j++) {
            int x,y; cin >> x >> y;
            sq[i].mi[0] = min(sq[i].mi[0],x); sq[i].ma[0] = max(sq[i].ma[0],x);
            sq[i].mi[1] = min(sq[i].mi[1],y); sq[i].ma[1] = max(sq[i].ma[1],y);
            sq[i].mi[2] = min(sq[i].mi[2],x + y); sq[i].ma[2] = max(sq[i].ma[2],x + y);
            sq[i].mi[3] = min(sq[i].mi[3],x - y); sq[i].ma[3] = max(sq[i].ma[3],x - y);
        }
    }

    for(int i = 1;i <= n;i++) {
        for(int j = i + 1;j <= n;j++) {

            bool ok = 1;
            for(int k = 0;k < 4;k++) {
                if(!iscross(sq[i].mi[k],sq[i].ma[k],sq[j].mi[k],sq[j].ma[k])) ok = 0;
            }

            if(ok) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }

        }
    }

    int ans = 0;

    for(int i = 1;i <= n;i++) {
        if(!vis[i]) {
            sz = 0;
            dfs(i);
            ans = max(ans,sz);
        }
    }
    cout << ans;
    return 0;
}