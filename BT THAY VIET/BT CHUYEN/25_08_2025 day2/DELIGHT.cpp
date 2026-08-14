#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 3000+7;
int n,t,q[MM];
vector<int> adj[MM];

void init()
{
    cin >> n >> t;
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}


namespace subtask1
{
    int color[MM];
    vector<int> light;
    
    bool validcheck()
    {
        queue<int> q;
        for(auto v:light) q.push(v);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            color[u] = 1-color[u];
            for(auto v:adj[u]) {
                color[v] = 1-color[v];
            }
        }
        for(int i = 1;i <= n;i++) if(!color[i]) return 0;
        return 1;
    }

    void solve()
    {
        for(int i = 1;i <= n;i++) {
            cin >> q[i];
            if(q[i]) color[i] = 1;
            else color[i] = 0;
        }
        for(int mask = 0;mask < (1 << n);mask++) {
            for(int i = 0;i < n;i++) {
                if(mask >> i & 1) light.push_back(i+1);
                if(q[i+1]) color[i+1] = 1;
                else color[i+1] = 0;
            }
            if(validcheck()) {
                cout << light.size() << ' ';
                for(auto v:light) cout << v << ' ';
                cout << '\n';
                return;
            }
            light.clear();
        }
        cout << -1 << '\n';
    }

}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "DELIGHT"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    init();
    while(t--) {
        subtask1::solve();
    }
    return 0;
}