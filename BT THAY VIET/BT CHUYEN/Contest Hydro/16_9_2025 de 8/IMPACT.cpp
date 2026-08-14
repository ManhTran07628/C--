#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 2e5+7;
int n,m,q;
ll a[MM],lt[MM];
vector<int> adj[MM],imp;

void readinput()
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        int p;
        cin >> p;
        if(p == 1) {
            lt[i] = 1;
            imp.push_back(i);
        }
    }
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> q;
}

namespace subtask1
{
    ll Val[MM],vis[MM],ans = 0;
    void dfs(int u)
    {
        vis[u] = 1;
        for(auto v:adj[u]) {
            if(lt[v]) continue;
            if(!vis[v]) {
                ans += Val[v];
                dfs(v);
            }
        }
    }

    void solve()
    {
        for(int i = 1;i <= n;i++) Val[i] = a[i];
        while(q--) {
            int t,u,x;
            cin >> t >> u;
            if(t == 1) {
                cin >> x;
                Val[u] = x;
            }
            else {
                ans = 0;
                memset(vis,0,sizeof(vis));
                dfs(u);
                ans += Val[u];
                cout << ans << '\n';
            }
        }
    }
}

namespace subtask3
{
    int vis[MM],comp[MM],Time = 0;
    ll Nsum[MM],Val[MM],TotalW[MM];
    vector<int> Nadj[MM];
    void pre_dfs(int u)
    {
        vis[u] = 1;
        comp[u] = Time;
        TotalW[Time] += Val[u];
        for(auto v:adj[u]) {
            if(lt[v]) continue;
            if(!vis[v]) {
                pre_dfs(v);
            }
        }
    }

    void solve()
    {
        for(int i = 1;i <= n;i++) Val[i] = a[i];
        for(int i = 1;i <= n;i++) {
            if(!comp[i] && !lt[i]) {
                Time++;
                pre_dfs(i);
            }
        }

        for(auto u:imp) {
            for(auto v:adj[u]) {
                if(!lt[v]) {
                    Nadj[comp[v]].push_back(u);
                }
            }
        }

        for(int i = 1;i <= Time;i++) {
            sort(Nadj[i].begin(),Nadj[i].end());
            Nadj[i].erase(unique(Nadj[i].begin(),Nadj[i].end()),Nadj[i].end());
            for(auto v:Nadj[i]) {
                Nsum[v] += TotalW[i];
            }
        }
        for(auto v:imp)  Nsum[v] += a[v];

        while(q--) {
            int t;
            ll u,x;
            cin >> t >> u;
            if(t == 1) {
                cin >> x;
                if(lt[u]) {
                    // Nsum[u] = Nsum[u] - a[u] + x;
                    a[u] = x;
                    continue;
                }
                ll tmp = x - a[u];
                a[u] = x;
                TotalW[comp[u]] += tmp;
            }
            else {
                ll ans = a[u];                   
                for(int c :Nadj[u]) {              
                    ans += TotalW[c];
                }
                cout << ans << '\n';
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    readinput();
    if(n <= 1000 && m <= 1000 && q <= 1000) subtask1::solve();
    else subtask3::solve();
    return 0;
}