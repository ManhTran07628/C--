#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
int n,k,st[MM],en[MM],m = 0;
ll a[MM],dp[MM][101],order[MM];
vector<int> adj[MM],tree[MM];
void readinput()
{
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u)
{
    st[u] = ++m;
    order[m] = u;
    for(auto v:adj[u]) {
        if(!st[v]) {
            dfs(v);
        }
    }
    en[u] = m;
    tree[en[u]].push_back(st[u]);
}

void solve()
{
    dfs(1);
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j <= k;j++) dp[i][j] = -oo;
    }
    for(int i = 1;i <= n;i++) {
        dp[i][0] = dp[i-1][0] + a[order[i]];
        for(int j = 1;j <= k;j++) {
            dp[i][j] = dp[i-1][j] + a[order[i]];
            for(auto v:tree[i]) {
                dp[i][j] = max(dp[i][j],dp[v-1][j-1]);
            }
        }
    }
    cout << dp[n][k];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readinput();
    solve();
    return 0;
}