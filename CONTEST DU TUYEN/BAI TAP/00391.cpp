#include <bits/stdc++.h>
using namespace std;

#define int long long
#define el '\n'
#define TASK ""
#define ii pair<int,int>
#define iii pair<int,ii>
#define pb push_back

constexpr int mod = 1e9+7;
constexpr int oo = 1e18;
constexpr int N = 1e6+5;

int n, dp[N];
vector<int> g[N];

void dfs(int u, int p)
{
    dp[u] = 1;
    for(int v : g[u])
    {
        if(v != p)
        {
            dfs(v,u);
            dp[u] += dp[v];
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    if  ( fopen( TASK".inp" , "r"  ) ){
        freopen( TASK".inp" , "r", stdin  );
        freopen( TASK".out" , "w", stdout  );
    }
    cin >> n ;
    for(int i = 2; i <= n; i++)
    {
        int u;
        cin >> u;
        g[u].pb(i);
        g[i].pb(u);
    }
    dfs(1,-1);
    for(int i=1; i <= n; i++) cout << dp[i] - 1<< " ";
    return 0;
}
