#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
int n,a[MM],h[MM];
vector<int> adj[MM],cur[MM],f[MM];

void dfs(int node,int par)
{
    if(node > n) return;
    
    h[node] = h[par] + 1;

    f[ h[node] ].push_back(node);

    dfs(node * 2,node);
    dfs(node * 2 + 1,node);
    
    for(auto x:adj[node * 2]) adj[node].push_back(x);
    adj[node].push_back(node);
    for(auto x:adj[node * 2 + 1]) adj[node].push_back(x);
    
    for(auto x:cur[node * 2]) cur[node].push_back(x);
    for(auto x:cur[node * 2 + 1]) cur[node].push_back(x);
    cur[node].push_back(node);


}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    dfs(1,0); 
    for(auto x:adj[1]) cout << a[x] << ' '; cout << '\n';
    for(auto x:cur[1]) cout << a[x] << ' '; cout << '\n';
    for(int i = 1;i <= n;i++) {
        for(auto x:f[i]) cout << a[x] << ' ';
    }

    return 0;
}