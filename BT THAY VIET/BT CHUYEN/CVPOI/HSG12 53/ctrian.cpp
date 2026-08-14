#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
#define pii pair<int,int>
const int MM = 1e5 + 7;
int n,N[MM][6],lcc[MM];
map<pii,vector<int>> mp;
vector<int> adj[MM];

void process()
{
    cin >> n;
    for(int i = 1;i <= n - 2;i++) {
        cin >> N[i][1] >> N[i][2] >> N[i][3] >> N[i][4];
        N[i][5] = i; lcc[ N[i][5] ] = -1;
        vector<int> vec;
        for(int j = 1;j <= 3;j++) vec.push_back(N[i][j]);
        sort(vec.begin(),vec.end());
        int a = vec[0], b = vec[1], c = vec[2];
        mp[{a,b}].push_back(i);
        mp[{b,c}].push_back(i);
        mp[{a,c}].push_back(i);
    } 

    for(auto E:mp) {
        int a = E.fi.fi, b = E.fi.se;
        vector<int> vec = E.se;
        if(vec.size() == 2) {
            int u = vec[0], v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
}


const int LOG = 17;
int d[MM],up[MM][LOG + 1],h[MM],res = 0,low[MM];
void dfs(int u)
{
    d[u] = N[u][4];
    for(auto v:adj[u]) {
        if(v == up[u][0]) continue;
        up[v][0] = u;
        h[v] = h[u] + 1;
        dfs(v);
    }
}

int LCK(int u,int v)
{
    if(h[v] > h[u]) swap(u,v);
    for(int i = LOG;i >= 0;i--)
        if(h[ up[u][i] ] >= h[v])
            u = up[u][i];
    if(u == v) return u;
    for(int i = LOG;i >= 0;i--)
        if(up[u][i] != up[v][i])
            u = up[u][i], v = up[v][i];
    return up[u][0];
}

void dfs2(int u)
{
    low[u] = h[ lcc[ d[u] ] ];
    for(auto v:adj[u]) {
        if(up[u][0] == v) continue;
        dfs2(v);
        low[u] = min(low[u],low[v]);
    }
    if(h[u] <= low[u]) res++;
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
    process();
    dfs(1);
    up[1][0] = 1;
    for(int j = 1;j <= LOG;j++)
        for(int i = 1;i <= n;i++)
            up[i][j] = up[ up[i][j-1] ][j-1];

    for(int i = 1;i <= n - 2;i++) {
        int d = N[i][4];
        if(lcc[d] == -1) lcc[d] = i;
        else lcc[d] = LCK(lcc[d],i);
    }
    dfs2(1);
    cout << res - 1;
    return 0;
}