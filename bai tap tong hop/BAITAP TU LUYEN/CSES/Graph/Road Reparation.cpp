#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int parent[MM];
ll n,m,total = 0;
struct Edge{
    int u,v,c;
};
vector<Edge> e;

int find_sets(int a)
{
    if(a == parent[a]) return a;
    return parent[a] = find_sets(parent[a]);
}

bool union_sets(int a,int b)
{
    a = find_sets(a);
    b = find_sets(b);
    if(a == b) return 0;
    parent[b] = a;
    return 1;
}




signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) 
        parent[i] = i;
    for(int i = 1;i <= m;i++) {
        int u,v,c;
        cin >> u >> v >> c;
        e.push_back({u,v,c});
    }
    sort(e.begin(),e.end(), [](Edge &a,Edge &b) {
        return a.c < b.c;
    });
    for(Edge d:e) {
        if(!union_sets(d.u,d.v)) continue;
        total += d.c;
    }
    int ok = 0;
    for(int i = 1;i <= n;i++) {
        if(parent[i] == i) ok++;
    }
    if(ok <= 1) cout << total;
    else cout << "IMPOSSIBLE";
    return 0;
}