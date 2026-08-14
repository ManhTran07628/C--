#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
int a[MM],vis[MM];
int n,t; 
bool check(int X)
{
    return (1 <= X && X <= n);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t;
    for(int i = 1;i < n;i++) {
        cin >> a[i];
    }
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        if(check(u + a[u])) q.push(u + a[u]);
    }
    if(vis[t]) cout << "YES";
    else cout << "NO";
    return 0;
}