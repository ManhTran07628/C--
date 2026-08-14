
#include<bits/stdc++.h>
using namespace std;
const int N = 2*1e3+1;
const int M = 1e4+1;
vector < pair <int, int> > g[N];
int vis[M], n, m, s[M];
bool check(int  key)
{
    memset(vis, 0, sizeof (vis));
    vis[1] = 1;
    deque<int> q;
    q.clear();
    q.push_back(1);
    while (!q.empty()){
            int u = q.front(); q.pop_front();
      for (auto v : g[u])
        if (!vis[v.first])
        if (v.second <= key){
            vis[v.first] = 1;
            q.push_back(v.first);
        }
    }
    for (int i=1; i<=n; i++)
        if (!vis[i])
         return 0;
    return 1;
}
int main()
{
    cin >> n >> m;
    for (int i=1; i<=m; i++){
            int a, b, c;
            cin >> a >> b >> c;
        g[a].push_back({b,c} );
        g[b].push_back({a,c} );
    }
    int l = 0, r = 1e9;
    int ans = 1e9;
    while (l < r){
        int mid = (l+r)/2;
       // cout << mid << endl;
        if ( check(mid) ){
                r = mid;
              ans = min(ans, mid);
        }
        else
            l = mid + 1;
    }
    while (!check(l)) l++;
    cout << l;
    return 0;
}