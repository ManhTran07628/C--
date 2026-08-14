#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int n,st[MM],en[MM];
pair<int,int> p;
vector<int> adj[MM];

void readinput()
{
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> p[i].fi;
        p[i].se = i;
    }
    for(int i = 2;i <= n;i++) {
        int u,v = i;
        cin >> u;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void solve()
{
    sort(p+1,p+n+1,greater<pair<int,int>>());
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}