#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<char,char>
const int MM = 25;
int t,n,m;
char c[MM];
vector<int> adj[1000];
string dp[MM][1 << 20];


void solve()
{
    cin >> n >> m;
    map<char,int> pos;
    for(int i = 0;i < n;i++) {
        cin >> c[i];
        pos[c[i]] = i;
    }
    for(int i = 1;i <= m;i++) {
        string s; cin >> s;
        int u = pos[s[0]], v = pos[s[1]];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0;i < n;i++)
        for(int j = 0;j < (1 << n);j++)
            dp[i][j] =  "{";
    dp[0][1] = c[0];
    for(int mask = 0;mask < (1 << n);mask++) 
        for(int u = 0;u < n;u++) {
            if((mask >> u & 1) == 0) continue;
            if(dp[u][mask] == "{") continue;
            for(auto v:adj[u]) {
                if((mask >> v & 1) == 0) 
                    dp[v][mask | (1 << v)] = min(dp[v][mask | (1 << v)],dp[u][mask] + c[v]);
            }
        }
    if(dp[n - 1][(1 << n) - 1] != "{") cout << dp[n - 1][(1 << n) - 1];
    else cout << "IMPOSSIBLE";
    cout << '\n';

    for(int i = 0;i < n;i++) 
        adj[i].clear();
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "lexhamil"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

