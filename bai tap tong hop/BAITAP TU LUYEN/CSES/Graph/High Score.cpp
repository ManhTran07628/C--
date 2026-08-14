#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 3000+7;
int n,m,dist[MM];
struct Node{
    int u,v;
    int w;
};
vector<Node> edge;

void Bellman_Ford()
{
    fill(dist+1,dist+n+1,-oo);
    dist[1] = 0;
    for(int i = 2;i <= n;i++) {
        for(auto k:edge) {
            int u = k.u;
            int v = k.v;
            int w = k.w;
            if(dist[u] != -oo && dist[v] < dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for(int i = 1;i <= n;i++) {
        for(auto k:edge) {
            int u = k.u;
            int v = k.v;
            int w = k.w;
            if(dist[u] != -oo && dist[v] < dist[u] + w) {
                dist[v] = oo;
            }
        }
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int a,b,x;
        cin >> a >> b >> x;
        edge.push_back({a,b,x});
    }
    Bellman_Ford();
    cout << (dist[n] != oo ? dist[n] : -1);
    return 0;
}